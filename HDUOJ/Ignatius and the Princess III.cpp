#include<iostream>
using namespace std;
const int MAX=130;
int c1[MAX],c2[MAX];//定义两个数组 
//数组c1[n]保存当前整数n能被拆分的总方法数
//而数组c2为中间量，起到过渡的作用 
int main()
{
	int i,j,k;
	int num;
	while(cin>>num && num>0)//输入num,即求n有多少种拆分方法数 
	{
		for(i=0;i<=num;i++)//初始化 
		{
			c1[i]=1;
			c2[i]=0;
		}
		for(i=2;i<=num;i++)
		{
			for(k=0;k<=num;k++)
				for(j=0;j+k<=num;j=j+i)
				c2[k+j]=c2[k+j]+c1[k];
			for(k=0;k<=num;k++)
			{
				c1[k]=c2[k];
				c2[k]=0;
			}
		}
		cout<<c1[num]<<endl;
	}
	return 0;
}
