//采用优先队列应该不会错啊！
#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

struct cmp{
       bool operator ()(const _int64 &i,const _int64 &j){
            return i>j;
         }
};


int prime[4]={2,3,5,7};

int main()
{
    _int64 dp[5843];
	int i,n;
	int k;
   priority_queue<_int64,vector<_int64>,cmp> q;//优先队列

    dp[0]=1;
	
	for(i=1;i<5842;i++)
    {
       for(k=0;k<4;k++)
       q.push(dp[i-1]*prime[k]);
	   while(q.top()==dp[i-1])//刚开始的时候我是写的 q.top()<=dp[i-1] ,不过按这样来写的话，dp[i]当i到了4000多的时候就会出错！
	   //队列输出的值应该比dp[i-1]大！
	   {//先解释一下写 q.top()==dp[i-1]的原因吧！由于 dp[i-1]=优先队列里的最小值 ，现在dp[i-1]的2,3,5,7倍入队列，也就是说
		//现在队列里的值都大于等于dp[i-1],由于该种数不允许重复，故一旦q.top()==dp[i-1]，就出队列！
		//我之前写的 q.top()<=dp[i-1]的<有些多余！
		//不过至于为什么会出错，我也不太清楚！
		    q.pop();
	   }
	    dp[i]=q.top();
	    q.pop();
     } 
	//先把dp[i]的2,3,5,7倍入队列，然后从队列里选一个大于dp[i-1]的最小的数当做dp[i];
     while(cin>>n && n != 0)
	{
         if((n%100)/10 !=1 )
		  {
		   if( n%10 == 1)
			printf("The %dst humble number is %d.\n",n,dp[n-1]);
		   else if( n%10 == 2)
		printf("The %dnd humble number is %d.\n",n,dp[n-1]);
		   else if( n%10 == 3)
			printf("The %drd humble number is %d.\n",n,dp[n-1]);
		   else
			printf("The %dth humble number is %d.\n",n,dp[n-1]);
		  }
		  else
		  printf("The %dth humble number is %d.\n",n,dp[n-1]);
	 }
    system("pause");
    return 0;
}
