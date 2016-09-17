
//代码超时！需要优化！！
#include <stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
	int a,b,i,c=1;
	int s[4];
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		a=a%10;
		for(i=1,c=1;i<4;i++)
		{
			c=c*a;
			s[i]=c%10;
		}
		c=c*a;
		s[0]=c%10;
	   
		i=b%4;
		cout<<s[i]<<endl;
	}
	
	return 0;
}
