#include <iostream>
#include <vector>
#include<stdio.h> 
using namespace std;
//打印结果
void printSolution(const vector<int> &v)
{
    for (vector<int>::const_iterator it = v.begin();it != v.end();++it)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
}

//构造递归函数，放第i个位置的数
void fun(vector<int> &v, vector<int> &f, int i)
{
    int n = v.size();
    for (int j=1;j<=n;++j)
    {
        //如果数j没有出现过，则第i个位置放j
        if (!f[j-1])
        {
            f[j-1] = 1;
            v[i] = j;
            //如果数全部放完，则打印结果
            if (i == n-1)
            {
                printSolution(v);
            }
            else
            {
                fun(v, f, i+1);
            }
            //回溯
            f[j-1] = 0;
        }
    }
}

int main()
{
    cout<<"输入n的值：";
    int n;  
    cin>>n;
    if (n<1)
    {
        cout<<"输入有误！"<<endl;
    }
    //记录全排列
    vector<int> v(n,0);
    //f[i]记录i+1是否出现过
    vector<int> f(n,0);
    fun(v, f, 0);
    return 0;
}
