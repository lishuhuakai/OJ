#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
     char str[1001];
	_int64 arr[1000],s,k;
	while(scanf("%s",str)!=EOF)
	{  
		k=0;
		for(int i=0;str[i]!='\0';)
		{   
			if(str[i]=='5')
			{
			  i++;
			  continue;
			}
			s=0;
			while(str[i]!='5' && str[i]!='\0')
			{
				s=s*10+str[i]-'0';i++;
			}
			arr[k++]=s;
		}
		
		sort(arr,arr+k);
		for(int i=0;i<k;i++)
		{
			if(i==k-1) cout<<arr[i];
			else
		    cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}