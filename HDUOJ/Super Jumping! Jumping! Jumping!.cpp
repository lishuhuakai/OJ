//��һ������̬�滮����Ŀ��ϣ���Լ����������ܹ����԰ɣ� 
//��һ�ζ�̬�滮����Ū���ˣ� 
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
      cin>>w[i];//һ��������ڵ��ϵ�ֵ,w[i]���ڼ�¼�ڵ��ϵ�ֵ��
      //���������Ƕ�̬�滮�ˣ���ǰ����ѣ� 
      //״̬ת�ƣ�dp[i]��ʾ��i�ڵ�Ϊ�յ㣬����ܷ�����ֵ
      //dp[i]=min{dp[k]+w[i],w[i]}
      //��һ�ԣ�
      dp[0]=w[0];//�ӵ�һ���㿪ʼ���Ե�һ����Ϊ�յ㣬��ֵһ��Ϊw[0];
      max=dp[0];
      for(i=1;i<n;i++)
      {  
         dp[i]=w[i];//��ʼʱ��dp[i]Ϊw[i];
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
