
//��չ��ŷ������㷨�ĵݹ���ʽ,�����ƹ���ȫ��������Χ
//�ش���ʽ
/*
#include<iostream>
using namespace std;

int extended_euclidean(int n,int m,int &x,int &y)
{
	if(m==0) { x=1;y=0;return n; }
	int g=extended_euclidean(m,n%m,x,y);
	int t=x-n/m*y;
	x=y;
	y=t;
	return g;
}
int main()
{
	int g,x,y;
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		g=extended_euclidean(n,m,x,y);
		printf("%d��%d�����Լ���ǣ�%d\n",n,m,g);
		printf("%d=%d*%d+%d*%d\n",g,x,n,y,m);
	}
}
*/


#include<iostream>
#include<cstdio>
using namespace std;

int extended_euclidean(int n,int m,int &x,int &y)//��չ��ŷ������㷨����һ����ʽ
{
	int x1=1, x2=0, x3=n;
	int y1=0, y2=1, y3=m;
	while(x3%y3!=0)
	{
		int d=x3/y3;
		int t1,t2,t3;
		t1=x1-d*y1;
		t2=x2-d*y2;
		t3=x3-d*y3;
		x1=y1; x2=y2; x3=y3;
		y1=t1; y2=t2; y3=t3;
	}
	x=y1; y=y2;
	return y3;
}
//���ڵ���ʽ���Ʒ���ǰ����ʦ�������������ˣ����ھ�ֻ�н�����

int main()
{
	int g,x,y;
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		g=extended_euclidean(n,m,x,y);
		printf("%d��%d�����Լ���ǣ�%d\n",n,m,g);
		printf("%d=%d*%d+%d*%d\n",g,x,n,y,m);
	}
	return 0;
}