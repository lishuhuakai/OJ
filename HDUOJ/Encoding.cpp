#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int cases;
	int i,k,s;
	string str;
	cin>>cases;
	for(i=0;i<cases;i++)
	{
		int alphabet[27]=
		{1,
		 1,1,1,1,1,1,1,
		 1,1,1,1,1,1,1,
		 1,1,1,  1,1,1,
		 1,1,1,  1,1,1,
		};
		cin>>str;
		for(k=0,s=1;k<str.length();)
		{
			int j=k+1;
			while(str[k]==str[j])
			{
             alphabet[s]++;
			   j++;
			}
			s++;
			if(alphabet[s-1]==1)
			printf("%c",str[k]);
			else
			printf("%d%c",alphabet[s-1],str[k]);
			k=j;
		}
		printf("\n");
	//虽然是一道很水的水题，不过不仔细想，还是会有很大的错误！
	//	alphabet[str[k]-'A']++;
	/*
	for(k=0;k<26;k++)
		{
			if(alphabet[k]==1)
			 printf("%c",k+'A');
		    if(alphabet[k]>1)
			printf("%d%c",alphabet[k],k+'A');
		}
        cout<<endl;
	}//此处代码错误在于输入的字母不一定按照字母表排列！有可能乱序！
	*/
	}
	return 0;

}