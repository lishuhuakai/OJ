#include <stdio.h>
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int j,k,a[1000],s;
	
           while(cin>>j && j>=0)
	{
			for(k=0,s=0;k<j;k++)
			{
				cin>>a[k];
				s=s+a[k];
			}
			cout<<s<<endl;
	}
	
	return 0;
}
