#include <iostream>
#include <vector>
#include<stdio.h> 
using namespace std;
//��ӡ���
void printSolution(const vector<int> &v)
{
    for (vector<int>::const_iterator it = v.begin();it != v.end();++it)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
}

//����ݹ麯�����ŵ�i��λ�õ���
void fun(vector<int> &v, vector<int> &f, int i)
{
    int n = v.size();
    for (int j=1;j<=n;++j)
    {
        //�����jû�г��ֹ������i��λ�÷�j
        if (!f[j-1])
        {
            f[j-1] = 1;
            v[i] = j;
            //�����ȫ�����꣬���ӡ���
            if (i == n-1)
            {
                printSolution(v);
            }
            else
            {
                fun(v, f, i+1);
            }
            //����
            f[j-1] = 0;
        }
    }
}

int main()
{
    cout<<"����n��ֵ��";
    int n;  
    cin>>n;
    if (n<1)
    {
        cout<<"��������"<<endl;
    }
    //��¼ȫ����
    vector<int> v(n,0);
    //f[i]��¼i+1�Ƿ���ֹ�
    vector<int> f(n,0);
    fun(v, f, 0);
    return 0;
}
