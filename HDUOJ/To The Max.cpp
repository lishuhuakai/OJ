//�������������m*n�ľ���ĳһ������ֵ
//���������㷨û�д��󣡵��ǳ�ʱ����˻�Ҫ��һ���Ż��㷨��
//����������˵�ıȽ�ģ������Ŀ��û��˵Ҫ����������ݣ�Ū����ֻ������һ�Σ��������Ǵ������Ҳ����������ڣ�
/*
#include<iostream>
#include<cstdio>
using namespace std;
const int MAX=10010;
int arr[MAX];

int main()
{
	int s,max=-200;
	int we=0;
	int m,n;
	while(scanf("%d",&arr[0])!=EOF)
	{
	//cin>>arr[0];//���뷽���ά��
	m=n=arr[0];
	for(int i=1;i<=arr[0]*arr[0];i++)
		cin>>arr[i];

	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)//�����Ǳ�ʾ�����Ĵ�С��i*j
			for(int p=1;m-p>=i-1 ;p++)
				for(int q=1;n-q>=j-1 ;q++)//����·�ߣ����϶��£���������
				{
					int cur=p+m*(q-1);
					int count=0;
					int temp=cur; 
					int temp1=1;
					s=0;
					//cout<<"��"<<we<<"�������� "<<endl;
					//cout<<"����� ����"<<p<<","<<"����"<<q<<endl;
					//cout<<"p="<<p<<",n="<<n<<endl;
					for(int k=1;k<=i*j;k++)
					{
						//cout<<arr[temp]<<"  ";
						s=s+arr[temp];
						count++;
						temp++;
						if(count>=i)
						{
							temp=cur+temp1*m;
							temp1++;
							count=0;
						}
					}
					//cout<<endl;
					//we++;
					if(s>max)
					max=s;
				}
     cout<<max<<endl;
	 //system("pause");
	 }
	return 0;
}
*/

#include<iostream>
#include<cstdio>
using namespace std;

int arr[101][101];
int sum[101],dp[101];

int main()
{
	
	int i,j,k,p,n;
	while(scanf("%d",&n)!=EOF)
	{  
		int max=-200;
		memset(sum,0,sizeof(sum));
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			cin>>arr[i][j];
		//�����뵽�����Ȼ��һ����̬�滮��
		//1��������ֶκ�
	/*
	��Ŀ����ת��Ϊ���������⣺
	1������n������������Ϊ��������ɵ�����a[1],a[2],a[3],��,a[n],���������a+a+��+a[j]���Ӷκ͵����ֵ��������������Ϊ����ʱ�����Ӷκ�Ϊ0�����˶��壬���������ֵΪMax{0,a+a+��+a[j]},1<=i<=j<=n
	���ǰ�b[j]���Ϊ��ǰ��ĳ�ʼ����a[j]��a[j]Ϊ���һ��Ԫ�أ��������Ķεĺ����ֵ����֪����ʼ��a[i]�ض�Ϊ������
��b[j]=max(a+..+a[j-1]+a[j]),����1<=i<=j,����1<=j<=n,��Ҫ��ȷ��һ����b[j]��ֵ�������a[j]�������������Ӷκ�Ϊmax{b[j]}��1<=j<=n��
	��b[j]�Ķ������֪����b[j-1]>0ʱ(��ǰ��Ķμ���a[j]��һ��ֵ�������Ȼ��a[j]��һ�ν���)b[j]=b[j-1]+a[j]����������ǰ��Ķ�Ϊ��ֵ������a[j],��ʹֵ��С�������Ļ������ǽ�ǰ��Ķ�ȥ����a[j]�������ֵ��b[j]=a[j]����b[j]�Ķ�̬�滮�ݹ�ʽΪ b[j]=max(b[j-1]+a[j],a[j])��1<=j<=n��
	2������Ӿ����

	�����Ƕ�ά�ģ�����ѹ����һά�Ϳ���������ķ����������Ӿ������
    ����һ��������ӣ�ѹ����һά�ļ��ɣ����Ǳ������е�ѹ�����ܣ��Ϳ���ͨ������ķ�����������ֵ��
	*/ 
		for(i=0;i<n;i++)
		{
			memset(sum,0,sizeof(sum));
			for(k=i;k<n;k++)
			{
				for(j=0;j<n;j++)
				sum[j]=arr[k][j]+sum[j];
					dp[0]=sum[0];
					for(p=1;p<n;p++)
					{
						if (dp[p-1]>0) dp[p]=dp[p-1]+sum[p];
                        else dp[p]=sum[p];
                        if (dp[p]>max) max=dp[p];
						/*
						if(dp[p-1]+sum[p]>sum[p])
							dp[p]=dp[p-1]+sum[p];
						else
							dp[p]=dp[p-1];
						if(dp[p]>max) max=dp[p];
						*/
					}
					
			}
		}
		cout<<max<<endl;
		//system("pause");
	}
	return 0;
}

