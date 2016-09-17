#include<stdio.h>
#include<string.h>
#define MAX 16
#define SIZE 1001
typedef struct 
{
	char name[MAX];
	int num;
}Balloon;

Balloon balnum[SIZE];
int main()
{
	int i,j,k,m;
	int max,line;
	char color[MAX];
	while(1)
	{
		scanf("%d",&m);//一共输入m个颜色
		if(m==0) break;
		for(i=0;i<m;i++)
			balnum[i].num=0;
        for(i=0,k=0;i<m;i++)
		{
			scanf("%s",color);
			for(j=0;j<k;j++)//从第一位搜索起
				if(strcmp(color,balnum[j].name)==0)//碰到了相同的颜色，那么该颜色数目就加1
			{
				balnum[j].num++;break;
			}
			if(j==k)//没碰到相同颜色，就添加颜色
			{
				strcpy(balnum[k].name,color); 
				balnum[k].num++;
				  k++;
			}
		}//统计子串个数的函数没有错误
		for(i=0,max=0,line=0;i<k;i++)
		{
            if(balnum[i].num>max) 
			{
				max=balnum[i].num;
				line=i;
			}
		}
		printf("%s\n",balnum[line].name);
	}
	return 0;
}