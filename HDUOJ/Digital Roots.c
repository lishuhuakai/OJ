/**********
�������ʱ��
***********
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char buff[100];
	int num,i=1;
	while(scanf("%d",&num)!=EOF)
	{
		if(num==0) return 0;
		while(1)
		{
			itoa(num,buff,10);
			for(i=0,num=0;buff[i]!='\0';i++)//i��buff�ĳ���
			 num=num+buff[i]-'1'+1;	
			if(i==1) 
			{
				printf("%d\n",num);
				break;
			}

		}
	}
	return 0;
}
/**************************

/**************************
���⣺wa��ԭ�򣺲�������̫��
**************************************/
/*************************************
#include<stdio.h>

int main()
{
	int num;
	while(scanf("%d",&num)!=EOF)
	{
		if(num==0) return 0;
		printf("%d\n",num%9?9:num%9);
		
	}
	return 0;
}
***************************************/
//�Ͼŷ���һ���������ָ����������ģ9��Ҳ���ڸ���λ������֮��ģ9��
#include<stdio.h>
#include<string.h>
int main()
{
	char  num[1000];
	int len,sum,i;
	while(scanf("%s",&num)!=EOF)
	{
		len=strlen(num);
		if(len==1 && num[0]=='0') return 0;
		for(sum=0,i=0;i<len;i++)
		{
			sum=sum+num[i]-'0';
		}
		printf("%d\n",sum%9?sum%9:9);//�Ͼŷ�;һ���������ָ����������ģ9��Ҳ���ڸ���λ������֮��ģ9
		
	}
	return 0;
}