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
	//��Ȼ��һ����ˮ��ˮ�⣬��������ϸ�룬���ǻ��кܴ�Ĵ���
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
	}//�˴�������������������ĸ��һ��������ĸ�����У��п�������
	*/
	}
	return 0;

}