//�������ȶ���Ӧ�ò������
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
 _int64 min(_int64 a,_int64 b,_int64 c,_int64 d)//ѡ����Сֵ
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
	x1=x2=x3=x4=0;//�ĸ�ָ�룬��ʼʱָ��dp[0]=1;
   // priority_queue<int,vector<int>,cmp> q;//���ȶ���

    dp[0]=1;
	
    /*
	for(i=1;i<5842;i++)
    {
       for(k=0;k<4;k++)
       q.push(dp[i-1]*prime[k]);
	   while(q.top() <= dp[i-1])//���������ֵӦ�ñ�dp[i-1]��
	   {
		    q.pop();
	   }
	    dp[i]=q.top();
	    q.pop();
     } 
	 */
	//���²ο��������޸Ĵ��룡�ܱ��ߣ������ľ������ȶ���Ӧ�ò��������ƫƫ��dp[4913]����ڵ㴦�����⣡
	//������˵�������е�ͨ�İ����Ȱ�dp[i]��2,3,5,7������У�Ȼ��Ӷ�����ѡһ������dp[i-1]����С��������dp[i];
	//ǰ4000������ݶ��ԣ�ƫƫ����ͷ����Ϊʲô����
	//��û�д�����Ը��ҽ���һ�°���
	for(i=1;i<5842;i++)//����ο����㷨��ȷ���ţ�
	{//һ���������Humble Numbers����ô����2,3,5,7������Humble Numbers��
      //x1ָʾdp[i]��2��
	  //x2Ϊ3������
	  //������ͼ���ɣ�
		 dp[i]=min(dp[x1]*2,dp[x2]*3,dp[x3]*5,dp[x4]*7);
		 if(dp[i]==dp[x1]*2) x1++;//�ѵ���,ָ�������Ų��Ų����һ��dp[x1]*2;
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
