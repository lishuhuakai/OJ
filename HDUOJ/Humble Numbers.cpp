//采用优先队列应该不会错啊！
#include<iostream>
//#include<queue>
#include<cstdio>
using namespace std;

/*
struct cmp{
       bool operator ()(const int &i,const int &j){
            return i>j;
         }
};
*/

//int prime[4]={2,3,5,7};
 _int64 min(_int64 a,_int64 b,_int64 c,_int64 d)//选出最小值
{
	_int64 min1=20000000001;
	if(min1>a) min1=a;
    if(min1>b) min1=b;
	if(min1>c) min1=c;
	if(min1>d) min1=d;
	return min1;
}
int main()
{
    _int64 dp[5843];
	int i,n;
	int x1,x2,x3,x4;
	x1=x2=x3=x4=0;//四个指针，开始时指向dp[0]=1;
   // priority_queue<int,vector<int>,cmp> q;//优先队列

    dp[0]=1;
	
    /*
	for(i=1;i<5842;i++)
    {
       for(k=0;k<4;k++)
       q.push(dp[i-1]*prime[k]);
	   while(q.top() <= dp[i-1])//队列输出的值应该比dp[i-1]大！
	   {
		    q.pop();
	   }
	    dp[i]=q.top();
	    q.pop();
     } 
	 */
	//以下参考而来的修改代码！很悲催！我真心觉得优先队列应该不会错啊！可偏偏在dp[4913]这个节点处出问题！
	//按道理说，这是行得通的啊！先把dp[i]的2,3,5,7倍入队列，然后从队列里选一个大于dp[i-1]的最小的数当做dp[i];
	//前4000多个数据都对，偏偏到后头出错！为什么啊？
	//有没有大神可以给我解释一下啊？
	for(i=1;i<5842;i++)//这个参考的算法的确很优！
	{//一个数如果是Humble Numbers，那么它的2,3,5,7倍都是Humble Numbers！
      //x1指示dp[i]的2倍
	  //x2为3倍……
	  //具体结合图看吧！
		 dp[i]=min(dp[x1]*2,dp[x2]*3,dp[x3]*5,dp[x4]*7);
		 if(dp[i]==dp[x1]*2) x1++;//搜到了,指针就往后挪！挪到下一个dp[x1]*2;
		 if(dp[i]==dp[x2]*3) x2++;
         if(dp[i]==dp[x3]*5) x3++;
	     if(dp[i]==dp[x4]*7) x4++;
	}
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
		 /* 
         if((n%100)/10 !=1 )
		  {
		   if( n%10 == 1)
			cout<<"The "<<n<<"st humble number is "<<dp[n-1]<<"."<<endl;
		   else if( n%10 == 2)
			cout<<"The "<<n<<"nd humble number is "<<dp[n-1]<<"."<<endl;
		   else if( n%10 == 3)
			cout<<"The "<<n<<"rd humble number is "<<dp[n-1]<<"."<<endl;
		   else
			cout<<"The "<<n<<"th humble number is "<<dp[n-1]<<"."<<endl;
		  }
		  else
		   cout<<"The "<<n<<"th humble number is "<<dp[n-1]<<"."<<endl;
           */
	 }
    system("pause");
    return 0;
}
