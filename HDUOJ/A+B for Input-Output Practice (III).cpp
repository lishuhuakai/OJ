#include <stdio.h>
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int a,b;
	while(1)
	{
		scanf("%d%d",&a,&b);
	  if(a==0 && b==0) return 0;
	  cout<<a+b<<endl;
	}
	return 0;
}
