#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int insort(int s[], int n)    /* 自定义函数 insort()*/
{
    int i,j;
    for(i=2;i<=n;i++)    //数组下标从2开始，s[0]做监视哨，s[1]一个数据无可比性
    {
        s[0]=s[i];    //给监视哨陚值
        j=i-1;    //确定要比较元素的最右边位黄
        while(s[0]<s[j])
        {
            s[j+1]=s[j];    //数据右移
            j--;    //产移向左边一个未比较的数
        }
        s[j+1]=s[0];    //在确定的位置插入s[i]
    }
    return 0;
}
int main()
{
    int a[N+1],i;    //定义数组及变量为基木整甩
    srand((unsigned)time(NULL));
	for(i=0;i<N;a[++i]=rand());
    insort(a,N);    //调用自定义函数 insort()
    printf("\n 插入数据排序后顺序：\n");
    for(i=1;i<=N;i++)
        printf("  %d",a[i]); //将排序后的数组输出
    printf("\n");
    return 0;
}


