#include<iostream>
#include<cstdio>
using namespace std;

typedef struct
{
	int bnum;
	int cnum;
	double flag;
}kinds;

void bubblesort(kinds a[],int n)
{
	int i,j;
	kinds t;
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
			if(a[j].flag<a[j+1].flag)
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
}

int main()
{
	int fnum,rnum;
    kinds a[1002];
	while(cin>>fnum>>rnum && (fnum!=-1 && rnum!=-1))
	{
		 double sum=0;
		 for(int i=0;i<rnum;i++)
		 {
			 cin>>a[i].bnum>>a[i].cnum;
			 a[i].flag=a[i].bnum*1.0/a[i].cnum;
		 }
         bubblesort(a,rnum);
		 for(i=0;i<rnum;i++)//�ü�����Ŀ������һ��i<rnum����Ȼwa
		 {//����Ҳʵ��̫�����ˣ��п���ʳ��̫���㣬�������з���Ķ��Ӷ������ˣ�����ʣ����Ȼ�����
			 if(fnum>=a[i].cnum)
			 {
				 sum=sum+a[i].bnum;
			    fnum=fnum-a[i].cnum;
			 }
			 else
			 {
				 sum=sum+1.0*fnum/a[i].cnum*a[i].bnum;
				 break;
			 }
		 }
		 printf("%.3lf\n",sum);
	}
	return 0;
}
/***************************
�������������������ǣ��Զ�����ת������������ܺ��ã�
int s;
double sum;
sum=1+1.0*s;//���﷢�����Զ�ת�� 1.0*sΪdouble���ˣ�
*****************************/