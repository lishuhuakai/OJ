#include <stdio.h>
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int i,j,s;
	int a[1000];
	while(cin>>j && j!=0)
	{
		for(i=0,s=0;i<j;i++)
		{
			cin>>a[i];
			s=s+a[i];
		}
		cout<<s<<endl;
		
	}
	return 0;
}
