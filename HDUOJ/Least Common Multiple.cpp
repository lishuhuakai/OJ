#include<iostream>
#include<algorithm>
using namespace std;
const SIZE=30;

bool compare(int a,int b)
{
      return a>b;   //升序排列，如果改为return a>b，则为降序
}
int main()
{
	int instances,num;//实例
	int mutiple[SIZE];
    int LCM,i,k,m;
	cin>>instances;
	for(m=0;m<instances;m++)
	{
		cin>>num;
		for(i=0;i<num;i++)
		 cin>>mutiple[i];

		sort(mutiple,mutiple+num,compare);//排序没有错误！
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