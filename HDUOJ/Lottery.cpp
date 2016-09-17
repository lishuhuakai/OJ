#include<iostream>
#include<cstdio>
using namespace std;

int gbs(int a,int b)//求最小公倍数
{
	int min;
	if(a==b) return a;
	else
	{
		min=a>b?b:a;
		for(int i=2;;i++)
		{
			if(min*i%a==0 && min*i%b==0)
				return min*i;
		}
	}

}

__int64 gys(__int64 m,__int64 n)//求最小公约数
{
	__int64 r;
	if(m<n)
	{
		r=m;m=n;n=r;
	}
	r=m%n;
	while(r)
	{
		m=n;n=r;r=m%n;
	}
	return n;
}
int main()
{
	int i,n,temp,temp2,temp3;
	__int64 fz1,fm1,fm2;
	while(cin>>n)
	{
		if(n<=0) break;
		fm1=1;
		fz1=n;
		
		//printf("%I64d,%I64d\n",fz1,fm1);
		for(i=2;i<=n;i++)
		{
			fm2=fm1;
			fm1=gbs(fm1,i);
			fz1=fz1*(fm1/fm2)+n*(fm1/i);
			//printf("分子是：%d,分母是：%d\n",fz1,fm1);
		}
		//printf("%d,%d/%d\n",fz1/fm1,fz1%fm1,fm1);
		if(fz1%fm1!=0)
		{
			temp=fz1/fm1;
			fz1=fz1-temp*fm1;
			temp2=gys(fz1,fm1);
			//printf("%I64d  %I64d  %I64d\n",fz1,fm1,temp2);
			fz1=fz1/temp2; fm1=fm1/temp2;
			if(temp<10)
			printf("  %I64d\n",fz1);
			else
			printf("   %I64d\n",fz1);
			printf("%I64d ",temp);
			temp3=fm1;
			while(temp3>0)
			{
				printf("-");
               temp3=temp3/10;
			   
			}
			printf("\n");
			if(temp<10)
			printf("  %I64d\n",fm1);
			else
            printf("   %I64d\n",fm1);

		}
        else
			printf("%I64d\n",fz1/fm1);

	}
	return 0;
}