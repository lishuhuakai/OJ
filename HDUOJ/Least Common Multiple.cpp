#include<iostream>
#include<algorithm>
using namespace std;
const SIZE=30;

bool compare(int a,int b)
{
      return a>b;   //�������У������Ϊreturn a>b����Ϊ����
}
int main()
{
	int instances,num;//ʵ��
	int mutiple[SIZE];
    int LCM,i,k,m;
	cin>>instances;
	for(m=0;m<instances;m++)
	{
		cin>>num;
		for(i=0;i<num;i++)
		 cin>>mutiple[i];

		sort(mutiple,mutiple+num,compare);//����û�д���
		for(i=0;i<num;i++)
		cout<<mutiple[i]<<"  ";
		cout<<endl;

		for(LCM=mutiple[0],k=1;k<num;k++)
		{
			 if(LCM%mutiple[k]!=0)
			 {
			  LCM=LCM+mutiple[0];k=0;
			 }
		}
		cout<<LCM<<endl;
	}
	return 0;
}