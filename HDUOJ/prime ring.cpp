//Prime Ring Problem
//这个程序也可以实现，得出正确答案，不过超时！
/*
#include <cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const SIZE=20;

int ring[38] = 
 {
     0, 0, 1, 1, 0, 1, 0, 
     1, 0, 0, 0, 1, 0, 1, 
     0, 0, 0, 1, 0, 1, 0, 
     0, 0, 1, 0, 0, 0, 0, 
     0, 1, 0, 1, 0, 0, 0,
     0, 0, 1,
 } ;
int k=1;
int Judge(int a[],int num)
{
	   int n; 
	   n=a[0]+a[num-1];
	   if(!ring[n]) return 0;
	   for(int k=0;k<num-1;k++)
		{   
			  n=a[k]+a[k+1];
			if(!ring[n]) return 0;
	   }
		return 1;//运行到这一步，表明是素数环
}

int main()
{
	int num=6,i;
	int prime[SIZE];
	while(1)
	{
		scanf("%d",&num);
		for(i=0;i<num;i++)
			prime[i]=i+1;
		printf("Case %d:\n",k);
		k++;
		do
		{
			if(Judge(prime,num))
			{
				
				
				for(i=0;i<num;i++)
				printf("%d ",prime[i]);
                printf("\n");
			}
		}while (next_permutation(prime+1,prime+num));//主要调用next_permutation函数
		printf("\n");
	}
	
	return 0;
}
*/

//这个算法很巧妙，真正佩服想出来的人！
#include <iostream>
#include<cstdio>
using namespace std;
 
// 小于37的所有素数
 int prime[38]= 
 {
     0, 0, 1, 1, 0, 1, 0, 
     1, 0, 0, 0, 1, 0, 1, 
     0, 0, 0, 1, 0, 1, 0, 
     0, 0, 1, 0, 0, 0, 0, 
     0, 1, 0, 1, 0, 0, 0,
     0, 0, 1,
 };//以空间换时间
 
// 输出一个解
 void Output(int a[], int n)
 {
    for(int i=0;i<n;i++)
	{
	  if(i==n-1)//坑爹的坑在这里，记住最后输出的没有空格，坑死在这里
      cout<<a[i];
	  else
      cout<<a[i]<<" ";
	}
     cout<<endl ;
 }
 
 // 判断当前序列是否满足条件
 bool IsOk(int a[], int lastIndex, int curValue)
 {
     if(lastIndex<0)//第一个元素没有前驱元素，返回真
         return true ;

     if(!((curValue+a[lastIndex]) & 1)) // 相邻的数奇偶性必然不同
         return false ;
 
     if(!prime[a[lastIndex]+curValue]) //相邻元素和为素数
         return false ;
 
     for(int i = 0; i <= lastIndex; i++) // 去重，curValue没有出现过
        if(a[i] == curValue)
         return false ;
 
     return true ;
 }
 
 void PrimeCircle(int a[], int n, int t)//在别的算法里，这里叫做dfs
 {
     if(n & 1)//奇数无解,直接返回
        return;
 
    if(t==n) 
     {
         if(prime[a[0]+a[n-1]])//判断首尾元素之和是否构成素数,刚才这里多了一个分号，仔细检查才发现，害人害个半死
             Output(a,n); 
     }
     else
     {
         for(int i=2;i<=n;i++)
         {
             a[t]=i;
             if(IsOk(a,t-1,i))//如果当前元素满足条件
             PrimeCircle(a,n,t+1);//进行下一次递归
         }
     }
 }
 
 int main()
 {
     int a[20],n,k=1;
     while(scanf("%d",&n)!=EOF)
	 {   
		 cout<<"Case "<<k<<":"<<endl;
		 k++;
		 a[0]=1;
		 PrimeCircle(a,n,1);
		 printf("\n");
	 }
     return 0 ;
 }
