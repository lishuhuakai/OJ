#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node
{
 int cases;
 float num;
}a[100];

bool cmp(node &a,node &b)
{
     return a.num>b.num;
}

bool cmp1(node &a,node &b)
{
	return a.cases>b.cases ;
}
 
int main()
{
    int m,n,k,i,j;
    float num;
    while(scanf("%d%d%d",&m,&n,&k)>0)
    {
		  for(i=0;i<n;i++)
		  {
			  a[i].cases=i+1;
			  a[i].num=0;
		  }
		  for(i=0;i<m;i++)
			  for(j=0;j<n;j++)
			  {
				cin>>num;
				a[j].num=a[j].num+num; 
			  } 
          sort(a,a+n,cmp); 
		  sort(a,a+k,cmp1);
          for(i=0;i<k;i++)
	    	if(i==k-1) cout<<a[i].cases<<endl;
             else  cout<<a[i].cases<<" ";	 
	}
    return 0;
}
