//�������ȶ���Ӧ�ò������
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
   priority_queue<_int64,vector<_int64>,cmp> q;//���ȶ���

    dp[0]=1;
	
	for(i=1;i<5842;i++)
    {
       for(k=0;k<4;k++)
       q.push(dp[i-1]*prime[k]);
	   while(q.top()==dp[i-1])//�տ�ʼ��ʱ������д�� q.top()<=dp[i-1] ,������������д�Ļ���dp[i]��i����4000���ʱ��ͻ����
	   //���������ֵӦ�ñ�dp[i-1]��
	   {//�Ƚ���һ��д q.top()==dp[i-1]��ԭ��ɣ����� dp[i-1]=���ȶ��������Сֵ ������dp[i-1]��2,3,5,7������У�Ҳ����˵
		//���ڶ������ֵ�����ڵ���dp[i-1],���ڸ������������ظ�����һ��q.top()==dp[i-1]���ͳ����У�
		//��֮ǰд�� q.top()<=dp[i-1]��<��Щ���࣡
		//��������Ϊʲô�������Ҳ��̫�����
		    q.pop();
	   }
	    dp[i]=q.top();
	    q.pop();
     } 
	//�Ȱ�dp[i]��2,3,5,7������У�Ȼ��Ӷ�����ѡһ������dp[i-1]����С��������dp[i];
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
