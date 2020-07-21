#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void Quick_sort(int a[],int first,int end) //快速排序 
{
	int temp,i,j;
	i=first;
	j=end;
	temp=a[i];    //初始化
	while(i<j)    //完成比temp大的在右边，比temp小的在左边
	{
		while((i<j)&&(a[j]>temp)) 
			j--;
		a[i]=a[j];
		while((i<j)&&(a[i]<=temp))
			i++;
		a[j]=a[i];
	}
	a[i]=temp;
	if((i-1)>first)	           //递归调用左半部数组部分
		Quick_sort(a,first,i-1);  //对左侧区域进行快速排序	
	if(end>(i+1))                //递归调用右半部数组部分
		Quick_sort(a,i+1,end);    //对右侧区域进行快速排序
}
int main()
{
    int i;
	int m[N];
    srand((unsigned)time(NULL));
	for(i=0;i<N;m[++i]=rand());
	
	
	Quick_sort(m,0,N);
	printf("从小到大排序后:\n");
	for(i=0;i<N;i++)
	{
	printf("    %d",m[i]);     //输出排序结果
	}
	printf( "\n" );
}
