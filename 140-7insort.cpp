#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int insort(int s[], int n)    /* �Զ��庯�� insort()*/
{
    int i,j;
    for(i=2;i<=n;i++)    //�����±��2��ʼ��s[0]�������ڣ�s[1]һ�������޿ɱ���
    {
        s[0]=s[i];    //���������ֵ
        j=i-1;    //ȷ��Ҫ�Ƚ�Ԫ�ص����ұ�λ��
        while(s[0]<s[j])
        {
            s[j+1]=s[j];    //��������
            j--;    //���������һ��δ�Ƚϵ���
        }
        s[j+1]=s[0];    //��ȷ����λ�ò���s[i]
    }
    return 0;
}
int main()
{
    int a[N+1],i;    //�������鼰����Ϊ��ľ��˦
    srand((unsigned)time(NULL));
	for(i=0;i<N;a[++i]=rand());
    insort(a,N);    //�����Զ��庯�� insort()
    printf("\n �������������˳��\n");
    for(i=1;i<=N;i++)
        printf("  %d",a[i]); //���������������
    printf("\n");
    return 0;
}


