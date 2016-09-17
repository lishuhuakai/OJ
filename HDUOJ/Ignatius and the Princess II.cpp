#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int SIZE=1002;

int main()
{
	int n,m;
	int i,count;
	int seq[SIZE];
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(i=0;i<SIZE;i++)
		seq[i]=i+1;
		 count=0;
		do
		{
			count++;
			if(count==m)
			{
				for(i=0;i<n;i++)
				if(i==n-1)
				cout<<seq[i];
				else
				cout<<seq[i]<<" ";
				cout<<endl;
				break;
			}
		}
		while (next_permutation(seq,seq+n));
	}
	return 0;
}
