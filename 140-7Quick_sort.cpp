#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void Quick_sort(int a[],int first,int end) //�������� 
{
	int temp,i,j;
	i=first;
	j=end;
	temp=a[i];    //��ʼ��
	while(i<j)    //��ɱ�temp������ұߣ���tempС�������
	{
		while((i<j)&&(a[j]>temp)) 
			j--;
		a[i]=a[j];
		while((i<j)&&(a[i]<=temp))
			i++;
		a[j]=a[i];
	}
	a[i]=temp;
	if((i-1)>first)	           //�ݹ������벿���鲿��
		Quick_sort(a,first,i-1);  //�����������п�������	
	if(end>(i+1))                //�ݹ�����Ұ벿���鲿��
		Quick_sort(a,i+1,end);    //���Ҳ�������п�������
}
int main()
{
    int i;
	int m[N];
    srand((unsigned)time(NULL));
	for(i=0;i<N;m[++i]=rand());
	
	
	Quick_sort(m,0,N);
	printf("��С���������:\n");
	for(i=0;i<N;i++)
	{
	printf("    %d",m[i]);     //���������
	}
	printf( "\n" );
}
