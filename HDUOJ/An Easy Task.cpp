#include<iostream>
using namespace std;

int main()
{
	int cases;
	int k;
	cin>>cases;
	while(cases--)
	{
		int y,n;
		cin>>y>>n;
		int num=0;
		for(k=y;;k++)
		{
			if(num==n) break;
			//�ж��ǲ�������
			if(k%4==0 && k%100!=0 || k%400==0)
				num++;
		}
		cout<<k-1<<endl;
	}
	system("pause");
	return 0;
}