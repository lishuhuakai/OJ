/*
//������������еĳ���,����㷨Ҳ����,����ֱ�ӳ�ʱ����������̫�࣡
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX=500010;

struct ARR
{
	int x,y;
}arr[MAX];

bool cmp(const ARR &a,const ARR &b)
{
	return a.x<b.x;
}
int dp[MAX],dp1[MAX];

int main()
{
	int n,count=0,i;
	while(scanf("%d",&n)!=EOF)
	{
		int temp;
		count++;
		for(i=0;i<n;i++)
		{
		 cin>>arr[i].x>>arr[i].y;
		 dp[i]=1;
		}
		sort(arr,arr+n,cmp);
		//��������Ϊ�ؼ��ģ��������������
		//��dp�����¼����������еĳ��ȣ�dp[i]��ʾ��arr[i]��ʼ����arr[i]������������еĳ��ȣ�
		//���Ǵ�arr[n-1]�Ӻ���ǰ�����������Ļ������arr[i].y<=arr[k].y(k>i && k<n),����dp[k]+1>dp[i],����dp[i]=dp[k]+1;
		//����һ���������֮����ҵ������е�dp[i];����ѡȡ����ֵ���ɣ�
		int t=0;
		for(int i=n-1;i>=0;i--)
		{  
			for(int k=i+1;k<n;k++)
			if(arr[i].y<=arr[k].y && dp[k]+1>temp)
			{
				temp=dp[i]=dp[k]+1;
				break;
			}
		}
		int max=0;
		for(int i=0;i<n;i++)
		{
			if(dp[i]>max)
			max=dp[i];
		}
		if(max==1) printf("Case %d:\nMy king, at most %d road can be built.\n\n",count,max);
		else printf("Case %d:\nMy king, at most %d roads can be built.\n\n",count,max);
	}
	return 0;
}
*/



//���򣺸�Ū�㶫������Ҳ�����ף�
//�����Ŀ��Ҫ������Ĳ��������У��ⶫ�����ѣ��ѵ��������ݷǳ��ض࣬ԭ����dp�Ͳ�����ô��Ч���ˣ�
//�����Ҫ�Ľ��㷨�������㷨�����벻�������������ҿ��˱Ƚ϶�Ĳ��ģ��ⷨ��ͬС�죬�����϶��ǰ������㷨�ɣ�
//�Ҿ��������Լ���������һ������㷨��
#include<iostream>
#include<algorithm>
using namespace std;
const int size=500050;

struct Co
{
	int a,b;
}arr[size];

int dp[size];//dp[i]����ʾ�ڳ���Ϊi�����е�����������е����һ��Ԫ�ص�ֵ

bool cmp(const Co &x,const Co &y)
{
	return x.a<y.a;
}

int main()
{
	int n,count=0,i;
	int len;
	while(scanf("%d",&n)!=EOF)
	{
		count++;
		for(i=1;i<=n;i++)
		cin>>arr[i].a>>arr[i].b;
		//memset(dp,0,sizeof(dp));
		sort(arr+1,arr+n+1,cmp);//�����Ȱ���arr[i].a��С����������Ϊ�������ݲ�һ����˳������
		len=1;//��ʼʱ����������len�ĳ���Ϊ1,
		dp[1]=arr[1].b;//�ȴ�arr[1]��ʼ��Ȼ���𲽼�����Ԫ��
		int low,high,mid;
		for(i=2;i<=n;i++)
		{
			low=1;high=len;//��1����len�ķ�Χ���������ҵ�һ�����ʵ�λ�ò���
			while(low<=high)
			{
				mid=(low+high)/2;
				if(arr[i].b<=dp[mid]) high=mid-1;//dp[i]����ʾ����Ϊi�����е�����������е����һ��Ԫ�ص�ֵ
				else low=mid+1;
			}
			//lowֻ������ֵ����ȡ��Ҫôlow<len,Ҫôlow=len+1,�����ɳ����ƶϳ���
			dp[low]=arr[i].b;//һ������Ḳ�ǵ��ϴ��ֵ���Զ��׼���dp[i]ԽС�������dp[k](k>i)����Ŀ����Ծͻ�Խ��
			//Ϊʲô��������������ϸ�۲죬���ֶ���һ��a[i].b��Ҫ�ж����Ƿ���ĳ�����������е�Ԫ�أ�����ֻ��Ҫ������ǰ���dp[j](j<len)�Ƚϼ��ɣ�����dp[j]��¼���ǵ�a[j].bΪֹ�����е�����������е����һ��Ԫ�أ����a[i],b>dp[j]����a[i].b<dp[j+1],��ô������ȻҪ��a[i].b����dp[j+1](�����ԣ�������г���Ϊj+1),�����a[i].b��dp[j]��ֵ������˵��a[i],b���Խ������е�dp[j]���棬��Ȼ����ѡ�����dp[len],��ˣ�����֮��len�ĳ���Ҫ�Լ�1
			//�������һ������,�᲻�����һ��ǰ��һ��dp[j]С��a[i].b,����Ҫ����j+1λ����dp[j+1]<a[i].b�أ������Ļ������ǾͲ����滻dp[j+1]�ˣ���ʵ�ϣ����dp[j]<a[i].b,dp[j+1]<a[i].b,����Ҫ����dp[j-1]�ĺ�,������dp[j+1]
			if(len<low)//���a[i].b��󣬴�ʱlow�����len��low=len+1;
			len=low;//����ʵ�ʱ�� len++
		}
		if(len==1) printf("Case %d:\nMy king, at most %d road can be built.\n\n",count,len);
		else printf("Case %d:\nMy king, at most %d roads can be built.\n\n",count,len);
	}
	return 0;
}