#include <iostream>
using namespace std;
int MatrixChain_GetOptimalValue(const int *p, int n, int *s)
{
	int *m=new int [(n+1)*(n+1)];
	// �������ټ����� 

	for (int i=1; i<=n; i++)
		m[i*(n+1)+i]=0;
	for (int r=2; r<=n; r++) // r�������ĳ��� 
	{
		for (int i=1; i<=n-r+1; i++) // i����������ʼλ��
		{
			int j=i+r-1; // j����������ֹλ��
			m[i*(n+1)+j]=m[(i+1)*(n+1)+j]+p[i-1]*p[i]*p[j];
			s[i*(n+1)+j]=i;
			
			for (int k=i+1; k<j; k++) // k�������ĶϿ�λ�� 
			{
				int t=m[i*(n+1)+k]+m[(k+1)*(n+1)+j]+p[i-1]*p[k]*p[j];
				if (t<m[i*(n+1)+j])
				{
					m[i*(n+1)+j]=t;
					s[i*(n+1)+j]=k;
				}
			}
		} 
	}
	
	int result=m[1*(n+1)+n];
	delete [] m;
	
	return result;
}

void MatrixChain_Traceback(int i, int j, int n, const int *s, int *t)
{
	if (i==j) return;
	int k=s[i*(n+1)+j];
	MatrixChain_Traceback(i, k, n, s, t);
	MatrixChain_Traceback(k+1, j, n, s, t);
	if (i!=k)
	{
		t[i+i]++;
		t[k+k+1]++;
	}
	if (k+1!=j)
	{
		t[k+k+2]++;
		t[j+j+1]++;
	}
}

void MatrixChain_PrintResult(int n, const int *t)
{
	for (int i=1; i<=n; i++)
	{
		for (int k=0; k<t[i+i]; k++)
			cout<<'(';
		cout<<'A'<<i;
		for (int k=0; k<t[i+i+1]; k++)
			cout<<')';
	}
	cout<<endl;
}

void MatrixChain(const int *p, int n)
{ 
	int *s=new int [(n+1)*(n+1)]; // �������ŶϿ�λ��
	int *t=new int [n+n+2]; // ÿ���������'('���������Ҳ�')'������
	for (int i=2; i<=n+n+1; i++) t[i]=0;
	
	int result=MatrixChain_GetOptimalValue(p, n, s);
	MatrixChain_Traceback(1, n, n, s, t);
	cout<<"���ټ�����="<<result<<endl;
	cout<<"���ų˷�˳��: ";
	MatrixChain_PrintResult(n, t);
	
	delete [] s;
	delete [] t;
}

int main(int argc, char *argv[]) {
	int n=6;
	int p[]={15,30,35,5,10,20,25};
	MatrixChain(p, n);
	
	cin.get();
	return 0;
}
