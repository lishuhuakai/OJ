#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int cases,k;
	cin>>cases;
	for(int i=0;i<cases;i++)
	{
		int s[100],num;
		cin>>num;
		for(k=0;k<num;k++)
		{
			cin>>s[k];
		}
		sort(s,s+k);
		for(k=0;k<num-1;k++)
			cout<<s[k]<<" ";
		cout<<s[num-1]<<endl;

	}
	return 0;
}
