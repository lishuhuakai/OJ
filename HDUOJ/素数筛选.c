#include<stdio.h>
#include<string.h>
const int  MAX 65543 
bool flag[MAX] ;
int prime[MAX/2];

//素数筛选模板 
void get_prime( int &k )//得到素数,k=0 
{
  memset(flag,true,sizeof(flag)) ;//标志为ture 
  int i,j;
  for(i=2;i<MAX;i++)
  {
      if(flag[i])
        prime[k++]=i;//prime数组里面存素数,k用来计数 
        //存i 
      for (j=0;j<k&& i*prime[j]<MAX ;j++ )//这里面直接是素数的筛选 
      {
          flag[i*prime[j]]=false;
          if (i%prime[j]==0) break;
      }
  }
}

int main ()
{
 int n,k=0;
 get_prime(k);//这里是得到所有的素数 
 while ( scanf ("%d",&n)!= EOF ) 
 {
       int i ;
       bool first=true;
       for ( i=0; i<k ; i++ )
       {
           while(n%prime[i]==0)//一旦可以被整除 
           {
                 if (first) 
                 {
                     printf("%d",prime[i]);
                     first=false;
                 }
                 else printf("*%d",prime[i]) ;
                 n /= prime[i]; 
           }
      }
      printf("\n");
 }
       return 0 ; 
}











// 合数过滤筛选法 Ver2 
// 参数：n 求解n以内(包括n)的素数
// 返回值：n以内素数个数 
int CompositeNumFilterV2(int n)
{
 int i, j;
 // 素数数量统计 
 int count = 0;
 // 分配素数标记空间，明白+1原因了吧，因为浪费了一个flag[0]
 char* flag = (char*)malloc( n+1 ); 
 
 // 初始化素数标记，要高效点咯
 flag[2] = 1;
 // 注意是i<n不是上例中的i<=n了，理由自思 
 for (i=3; i<n; i++)
 {
  flag[i++] = 1;
  // 偶数自然不是素数，直接置0好了 
  flag[i] = 0;
 }
 // n为奇数 
 if (n%2 != 0)
 {
  flag[n] = 1;
 }
 
 // 从3开始filter，因为2的倍数早在初始化时代就干掉了
 // 到n/2止的理由还要说吗 
 for (i=3; i <= n/2; i++)
 {
  // i是合数，请歇着吧，因为您的工作早有您的质因子代劳了 
  if (0 == flag[i]) continue;
  
  // 从i的2倍开始过滤，变乘法为加法  
  for (j=i+i; j <= n; j+=i)
  {
   flag[j] = 0;
  }
 }
 
 // 统计素数个数
 for (i=2; i<=n; i++)
 {
  if (flag[i]) count++;
 }
  
 // 因输出费时，且和算法核心相关不大，故略
  
 // 释放内存，别忘了传说中的内存泄漏 
 free(flag);
 
 return count;
} 





