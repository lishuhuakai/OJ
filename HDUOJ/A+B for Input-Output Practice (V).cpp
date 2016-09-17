#include <stdio.h>
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int cases;
	cin>>cases;
	int j,s,k;
	int a[1000];
	for(int i=0;i<cases;i++)
	{
            cin>>j;
			for(k=0,s=0;k<j;k++)
			{
				cin>>a[k];
				s=s+a[k];
			}
			cout<<s<<endl;
	}
	
	return 0;
}
