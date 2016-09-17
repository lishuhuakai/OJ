#include<stdio.h>

int main()
{
	int i,j,start,end,start1;
	int m,n,k;
	int sum;//sum的值赋为0
	int max;
	scanf("%d",&m);
	for(i=0;i<m;i++)//一共有多少组数据
	{
       sum=0;max=-1001;start1=0;
		scanf("%d",&k);//一组数据一共有多少个数字
		for(j=0;j<k;j++)
		{
			scanf("%d",&n);//依次输入n的值
			sum=sum+n;//sum依次添加n
			if(sum>max)
			{
				max=sum;
				start=start1;
				end=j;
			}
			if(sum<0)
			{
				sum=0;
				start1=j+1;//更新下标
			}
		}

     printf("Case %d:\n",i+1);
	 printf("%d %d %d\n",max,start+1,end+1);
	 if(i<m-1)
	 printf("\n");
	}
	return 0;
}


/*
#include<stdio.h>
#define MAX 100001
int main()
{
	int i,j,k,start,end;
	int m,n;
	int max,s;
	int sequence[MAX];
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&n);//一共n个数；
		max=0;
		start=0;
		end=0;
		for(j=0;j<n;j++)
			scanf("%d",&sequence[j]);
		for(j=0;j<n;j++)
			for(s=sequence[j],k=j+1;k<n;k++)
		{  
			s=s+sequence[k];
		    if(s>max)
			{ 
				max=s;
                start=j;
				end=k;//记录下开始以及结束的下标
			}

		}
     printf("Case %d:\n",i+1);
	 printf("%d %d %d\n",max,start+1,end+1);
	 if(i<m-1)
	 printf("\n");
	}
 return 0;
}
*/