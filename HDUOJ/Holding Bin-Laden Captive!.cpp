//母函数问题，整数的拆分

//以前做过这一类的题，现在回顾一下
//我靠，这道题貌似比以前做的母函数的题目还要简单
//只要求出有多少种组合方案就可以了
//以下的两种方法皆可以做！
/*
#include<iostream>
using namespace std;

int main()
{
	int n,m,j,i,k;
	while(cin>>m>>n>>k &&( m!=0 || n!=0 || k!=0))
	{
		int flag[10001],temp[10001];//用于标志可不可以组合，如果可以组合出i，则flag[i]=1,否则为0
		memset(flag,0,sizeof(flag));//初始化，全部标为0
		memset(temp,0,sizeof(temp));
		for(i=0;i<=m;i++)  flag[i]=1;//先是1
		for(i=0;i<=n*2;i=i+2)//再2
		{
			for(j=0;j<=m;j++)
			temp[i+j]=1;
		}
		for(i=0;i<=m+2*n;i++)
			if(temp[i]==1)
				flag[i]=1;
		memset(temp,0,sizeof(temp));
		for(i=0;i<=k*5;i=i+5)//再5
		{
			for(j=0;j<=m+2*n;j++)
				if(flag[j]==1)
					temp[i+j]=1;
		}
		for(i=0;i<=m+2*n+5*k;i++)
			if(temp[i]==1)
				flag[i]=1;
		for(i=0;i<=2*n+m+5*k;i++)
		{
			if(flag[i]==0)
				break;
		}
		cout<<i<<endl;
	}


	return 0;
}
*/

#include<iostream>
using namespace std;
const int lmax=10000;
int c1[lmax+1],c2[lmax+1];

int main()
{
	int n,m,k,i,j;
	while(cin>>m>>n>>k && (m!=0 || n!=0 || k!=0))
	{
		int sum=m+2*n+5*k;
		for(i=0;i<=sum;i++){c1[i]=0;c2[i]=0;}
		for(i=0;i<=m;i++) c1[i]=1;

			for(i=0;i<=m;i++)
				for(j=0;j<=2*n;j=j+2)
					c2[i+j]+=c1[i]; 
		for(j=0;j<=sum;j++){c1[j]=c2[j];c2[j]=0;}

		for(i=0;i<=m+2*n;i++)
			for(j=0;j<=k*5;j=j+5)
              c2[j+i]+=c1[i]; 
		for(j=0;j<=sum;j++){c1[j]=c2[j];c2[j]=0;}


     for(i=0;i<=sum;i++)  
     {  
          if(c1[i]==0)   
          {printf("%d\n",i);break;}  
      }  
     if(i==sum+1)  
       printf("%d\n",i);  
		
	}
	return 0;
}

