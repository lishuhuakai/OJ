#include<iostream>
using namespace std;
const int MAX=100;

int main()
{
	int floors[MAX];
	int times;
	while(cin>>times && times!=0)
	{
		int curfloor=0;
		int sum=0;
		int i;
		for(i=0;i<times;i++)
		{
          cin>>floors[i];
		}
		for(i=0;i<times;i++)
		{
			  while(curfloor<floors[i])
			  {
				curfloor++;
				sum=sum+6;
			  }
			  while(curfloor>floors[i])
			  {
				curfloor--;
				sum=sum+4;
			  }
			  sum=sum+5;
		}
		cout<<sum<<endl;
	}
	return 0;
}