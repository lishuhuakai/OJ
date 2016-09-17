#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
const int SIZE=100;

int step[4][2]={0,-1,  1,0,  0,1, -1,0};

int main()
{
	string str[SIZE];
	char flag;
	int row,line,place;
	int loop;
	int i,m,n,k;
	int p,q;
	while(scanf("%d%d%d",&row,&line,&place))//行列
	{
		if(row==0 && line==0 && place==0) break;
		for(i=0;i<row;i++)
		{
			cin>>str[i];
		}
		flag=str[0][place-1];
		

		m=0;  n=place-1;  k=0;
		

		loop=0;
		while(0<=m && m<row && 0<=n && n<line)
		{	
			
			
			p=m;q=n;
			flag=str[m][n];//取得该处的值

			if(flag!='E' && flag!='W' && flag!='S' && flag!='N')
			{
				loop=1;
				break;
			}//不为这四点说明循环！就退出！

            
			str[m][n]=1+k;
            
			k++;
		
			switch(flag)
			{
				case 'N':m=m+step[0][1];n=n+step[0][0]; break;
				case 'E':m=m+step[1][1];n=n+step[1][0]; break;
				case 'S':m=m+step[2][1];n=n+step[2][0]; break;
				case 'W':m=m+step[3][1];n=n+step[3][0]; break;
			}
			
			
		}
		if(loop)
		printf("%d step(s) before a loop of %d step(s)\n",str[m][n]-1,k+1-str[p][q]);
		else
		printf("%d step(s) to exit\n",str[p][q]);
	}
	return 0;
}