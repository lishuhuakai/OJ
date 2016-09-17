#include <iostream>
#include<stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
    int a,b;
	int cases;
	cin>>cases;
	for(int i=0;i<cases;i++)
	{
		scanf("%d%d",&a,&b);
		cout<<a+b<<endl;
	}
	
	return 0;
}