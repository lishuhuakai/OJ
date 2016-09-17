//第一次做动态规划的题目，希望自己用心做！能够做对吧！ 
//第一次动态规划总算弄对了！ 
#include<iostream>
using namespace std;

int main()
{
    int n;
    int i,j,max,max1;
    int w[1002],dp[1002];
    while(cin>>n)
    {
      if(n==0) break;
      for(i=0;i<n;i++)
      cin>>w[i];//一个个输入节点上的值,w[i]用于记录节点上的值！
      //接下来就是动态规划了！从前向后搜！ 
      //状态转移！dp[i]表示以i节点为终点，获得总分最大的值
      //dp[i]=min{dp[k]+w[i],w[i]}
      //试一试！
      dp[0]=w[0];//从第一个点开始，以第一个点为终点，其值一定为w[0];
      max=dp[0];
      for(i=1;i<n;i++)
      {  
         dp[i]=w[i];//开始时置dp[i]为w[i];
         //max1=w[i];
         for(j=0;j<i;j++)
         if(w[i]>w[j] && dp[j]+w[i]>dp[i])
         {
          //max1=dp[j]+w[i];
          dp[i]=dp[j]+w[i]; 
          }
       }
       for(i=0;i<n;i++)
       if(dp[i]>max)
       max=dp[i];
       cout<<max<<endl;
    }
} 
