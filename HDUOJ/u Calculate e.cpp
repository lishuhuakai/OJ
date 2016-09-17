#include<iostream>
#include<cstdio>
using namespace std;
int multip[10]={1,1,2,6,24,120,720,5040,40320,362880};

double calcul(int n)
{
	double s=0;
	int i;
	 for(i=0;i<=n;i++)
	 {
		 s=s+1.0/multip[i];
	 }
	 return s;
}
int main()
{
	int i;
	printf("n e\n");
    printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	for(i=3;i<=9;i++)
	printf("%d %.9lf\n",i,calcul(i));
}