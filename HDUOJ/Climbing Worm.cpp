#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,u,d;
	int s,k;
	while(cin>>n>>u>>d)
	{
		if(n==0 && u==0 && d==0) break;
		s=k=0;
		while(1)
		{
			s=s+u;
			k++;
			if(s>=n) break;
			s=s-d;
			k++;
		}
		cout<<k<<endl;
	}

	return 0;
}