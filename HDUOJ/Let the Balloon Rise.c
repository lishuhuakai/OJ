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
		scanf("%d",&m);//һ������m����ɫ
		if(m==0) break;
		for(i=0;i<m;i++)
			balnum[i].num=0;
        for(i=0,k=0;i<m;i++)
		{
			scanf("%s",color);
			for(j=0;j<k;j++)//�ӵ�һλ������
				if(strcmp(color,balnum[j].name)==0)//��������ͬ����ɫ����ô����ɫ��Ŀ�ͼ�1
			{
				balnum[j].num++;break;
			}
			if(j==k)//û������ͬ��ɫ���������ɫ
			{
				strcpy(balnum[k].name,color); 
				balnum[k].num++;
				  k++;
			}
		}//ͳ���Ӵ������ĺ���û�д���
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