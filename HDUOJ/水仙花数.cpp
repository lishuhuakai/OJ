#include<iostream>
using namespace std;

int main()
{
	int m,n,temp;
	int a,b,c,s,flag;
	
	while(cin>>m>>n)
	{   
		if(m<=99 && n<=99) break;
		s=0; flag=0;
		for(;m<=n;m++)
		{
			a=m%10;temp=m/10;
			b=temp%10;temp=temp/10;
			c=temp;
			if(a*a*a+b*b*b+c*c*c==m)
			{   
				if(flag!=0)
				cout<<" ";
				cout<<m;
				flag=1;
				s++;
			}
		}
		if(s==0) cout<<"no"<<endl;
		else
		cout<<endl;
	}
	system("pause");
	return 0;
}