#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
  
#define N 10         // 带编码字符的个数，即树中叶结点的最大个数  
#define M (2*N-1)    // 树中总的结点数目  
  
class HTNode{        // 树中结点的结构  
public:   
    unsigned int weight;  
    unsigned int parent,lchild,rchild;  
};                      
  
class HTCode{  
public:  
    char data;      // 待编码的字符  
    int weight;     // 字符的权值  
    char code[N];   // 字符的编码  
};  
  
void Init(HTCode hc[], int n){  
// 初始化，读入待编码字符的个数n，从键盘输入n个字符和n个权值  
    int i;  
    printf("input %d character\n",n);  
      
    for(i=1; i<=n; ++i)  
		cin>>hc[i].data;
 
    printf("\ninput %d weight\n",n);  
      
    for(i=1; i<=n; ++i)  
        scanf("%d",&(hc[i].weight));  
}//  
  
//遍历节点数组ht中前i-1个节点，在所有父节点为0的节点中找出最小的两个节点s1,s2
void Select(HTNode ht[], int k, int *s1, int *s2){  
// ht[1...k]中选择parent为0，并且weight最小的两个结点，其序号由指针变量s1，s2指示  
    int i;  
    for(i=1; i<=k && ht[i].parent != 0; ++i){   
        ; ;  
    }  
    *s1 = i;  
  
    for(i=1; i<=k; ++i){  
        if(ht[i].parent==0 && ht[i].weight<ht[*s1].weight)  
            *s1 = i;  
    }  
  
    for(i=1; i<=k; ++i){  
        if(ht[i].parent==0 && i!=*s1)  
            break;  
    }  
    *s2 = i;  
  
    for(i=1; i<=k; ++i){  
        if(ht[i].parent==0 && i!=*s1 && ht[i].weight<ht[*s2].weight)  
            *s2 = i;  
    }  
}  
  
void HuffmanCoding(HTNode ht[],HTCode hc[],int n){  
// 构造Huffman树ht，并求出n个字符的编码  
    char cd[N];  
    int i,m,c,f,s1,s2,start;  
    m = 2*n-1;  
    
	//设置要编码的节点的权值。把把所有节点的父节点孩子节点都设为0
    for(i=1; i<=m; ++i)
	{  
        if(i <= n)  
            ht[i].weight = hc[i].weight;  
        else  
            ht[i].parent = 0;  
        ht[i].parent = ht[i].lchild = ht[i].rchild = 0;  
    }  
	//在要编码的节点后计算当前的父节点，把父节点填入下一个位置，设置该父节点的父节点，左右孩子节点和权值
    for(i=n+1; i<=m; ++i)
	{  
        Select(ht, i-1, &s1, &s2);  
        ht[s1].parent = i;  
        ht[s2].parent = i;  
        ht[i].lchild = s1;  
        ht[i].rchild = s2;  
        ht[i].weight = ht[s1].weight+ht[s2].weight;  
    }  
  
    cd[n-1] = '\0';  
  
    for(i=1; i<=n; ++i)
	{  
        start = n-1;  
        for(c=i,f=ht[i].parent; f; c=f,f=ht[f].parent)   
		//对要编码的节点从下向上遍历，当该节点是父节点的左孩子节点时编码置0，否之置1
		{  
            if(ht[f].lchild == c)  
                cd[--start] = '0';  
            else  
                cd[--start] = '1';  
        }  
        strcpy(hc[i].code, &cd[start]);  
    }  
}  
  
  
int main()  
{  
    int i,n;  
    HTNode ht[M+1];  
    HTCode hc[N+1];  
	printf("input n=");  
    cin>>n;
    Init(hc,n);     // 初始化  
    HuffmanCoding(ht,hc,n);   // 构造Huffman树，并形成字符的编码  
  
    for(i=1; i<=n; ++i)    
        printf("\n%c---%s",hc[i].data,hc[i].code);    
    printf("\n");  
  
    return 0;  
}  
