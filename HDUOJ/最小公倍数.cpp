#include<iostream>
using namespace std;

int main()
{
	int m,n;
	int min;
	while(cin>>m>>n)
	{
		if(m==0 && n==0) break;
		if(m==n) cout<<m<<endl;
		else 
		{
			min=m>n?n:m;
			for(int i=2; ;i++)
			{
				if(min*i%m==0 && min*i%n==0) break;
			}
			cout<<min*i<<endl;
		}
	}
	return 0;
}