//这个程序可以求出m*n的矩阵某一块的最大值
//这种搜索算法没有错误！但是超时，因此还要进一步优化算法！
//这道题的题意说的比较模糊，题目里没有说要多个测试数据，弄得我只处理了一次，导致老是错误，又找不到问题所在！
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
	//cin>>arr[0];//输入方阵的维数
	m=n=arr[0];
	for(int i=1;i<=arr[0]*arr[0];i++)
		cin>>arr[i];

	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)//这里是表示块数的大小，i*j
			for(int p=1;m-p>=i-1 ;p++)
				for(int q=1;n-q>=j-1 ;q++)//搜索路线，自上而下，自左向右
				{
					int cur=p+m*(q-1);
					int count=0;
					int temp=cur; 
					int temp1=1;
					s=0;
					//cout<<"第"<<we<<"次搜索： "<<endl;
					//cout<<"起点是 行数"<<p<<","<<"列数"<<q<<endl;
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
		//很难想到，这居然是一道动态规划题
		//1、最大子字段和
	/*
	题目可以转化为两个子问题：
	1，给定n个整数（可能为负数）组成的序列a[1],a[2],a[3],…,a[n],求该序列如a+a+…+a[j]的子段和的最大值。当所给的整均为负数时定义子段和为0，依此定义，所求的最优值为Max{0,a+a+…+a[j]},1<=i<=j<=n
	我们把b[j]理解为从前面某项开始包含a[j]（a[j]为最后一个元素）的连续的段的和最大值，易知，开始的a[i]必定为正数！
记b[j]=max(a+..+a[j-1]+a[j]),其中1<=i<=j,并且1<=j<=n,需要明确的一点是b[j]的值必须包含a[j]。则所求的最大子段和为max{b[j]}，1<=j<=n。
	由b[j]的定义可易知，当b[j-1]>0时(即前面的段加上a[j]这一段值会更大，自然把a[j]这一段接上)b[j]=b[j-1]+a[j]，否则（由于前面的段为负值，加上a[j],会使值变小，这样的话，我们将前面的段去掉，a[j]即是最大值）b[j]=a[j]。故b[j]的动态规划递归式为 b[j]=max(b[j-1]+a[j],a[j])，1<=j<=n。
	2、最大子矩阵和

	矩阵是二维的，将其压缩成一维就可以用上面的方法求出最大子矩阵和了
    即将一层层的数相加，压缩成一维的即可，我们遍历所有的压缩可能，就可以通过上面的方法，求出最大值！
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

