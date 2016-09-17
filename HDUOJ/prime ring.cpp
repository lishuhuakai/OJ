//Prime Ring Problem
//�������Ҳ����ʵ�֣��ó���ȷ�𰸣�������ʱ��
/*
#include <cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const SIZE=20;

int ring[38] = 
 {
     0, 0, 1, 1, 0, 1, 0, 
     1, 0, 0, 0, 1, 0, 1, 
     0, 0, 0, 1, 0, 1, 0, 
     0, 0, 1, 0, 0, 0, 0, 
     0, 1, 0, 1, 0, 0, 0,
     0, 0, 1,
 } ;
int k=1;
int Judge(int a[],int num)
{
	   int n; 
	   n=a[0]+a[num-1];
	   if(!ring[n]) return 0;
	   for(int k=0;k<num-1;k++)
		{   
			  n=a[k]+a[k+1];
			if(!ring[n]) return 0;
	   }
		return 1;//���е���һ����������������
}

int main()
{
	int num=6,i;
	int prime[SIZE];
	while(1)
	{
		scanf("%d",&num);
		for(i=0;i<num;i++)
			prime[i]=i+1;
		printf("Case %d:\n",k);
		k++;
		do
		{
			if(Judge(prime,num))
			{
				
				
				for(i=0;i<num;i++)
				printf("%d ",prime[i]);
                printf("\n");
			}
		}while (next_permutation(prime+1,prime+num));//��Ҫ����next_permutation����
		printf("\n");
	}
	
	return 0;
}
*/

//����㷨��������������������ˣ�
#include <iostream>
#include<cstdio>
using namespace std;
 
// С��37����������
 int prime[38]= 
 {
     0, 0, 1, 1, 0, 1, 0, 
     1, 0, 0, 0, 1, 0, 1, 
     0, 0, 0, 1, 0, 1, 0, 
     0, 0, 1, 0, 0, 0, 0, 
     0, 1, 0, 1, 0, 0, 0,
     0, 0, 1,
 };//�Կռ任ʱ��
 
// ���һ����
 void Output(int a[], int n)
 {
    for(int i=0;i<n;i++)
	{
	  if(i==n-1)//�ӵ��Ŀ��������ס��������û�пո񣬿���������
      cout<<a[i];
	  else
      cout<<a[i]<<" ";
	}
     cout<<endl ;
 }
 
 // �жϵ�ǰ�����Ƿ���������
 bool IsOk(int a[], int lastIndex, int curValue)
 {
     if(lastIndex<0)//��һ��Ԫ��û��ǰ��Ԫ�أ�������
         return true ;

     if(!((curValue+a[lastIndex]) & 1)) // ���ڵ�����ż�Ա�Ȼ��ͬ
         return false ;
 
     if(!prime[a[lastIndex]+curValue]) //����Ԫ�غ�Ϊ����
         return false ;
 
     for(int i = 0; i <= lastIndex; i++) // ȥ�أ�curValueû�г��ֹ�
        if(a[i] == curValue)
         return false ;
 
     return true ;
 }
 
 void PrimeCircle(int a[], int n, int t)//�ڱ���㷨��������dfs
 {
     if(n & 1)//�����޽�,ֱ�ӷ���
        return;
 
    if(t==n) 
     {
         if(prime[a[0]+a[n-1]])//�ж���βԪ��֮���Ƿ񹹳�����,�ղ��������һ���ֺţ���ϸ���ŷ��֣����˺�������
             Output(a,n); 
     }
     else
     {
         for(int i=2;i<=n;i++)
         {
             a[t]=i;
             if(IsOk(a,t-1,i))//�����ǰԪ����������
             PrimeCircle(a,n,t+1);//������һ�εݹ�
         }
     }
 }
 
 int main()
 {
     int a[20],n,k=1;
     while(scanf("%d",&n)!=EOF)
	 {   
		 cout<<"Case "<<k<<":"<<endl;
		 k++;
		 a[0]=1;
		 PrimeCircle(a,n,1);
		 printf("\n");
	 }
     return 0 ;
 }
