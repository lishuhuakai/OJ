//Fibonacci Again!�����Ŀ���к�ǿ�Ĺ����ԣ�
//���ǽ��������еĳ�3�������ڳ�����һ����֪���ˣ�
//  1,2,0,2,2,1,0;(��3��1�������ϳ�3��2������ӣ���һ����3ȡ0����)
//1,1,2,0,2,2,1,0;(����������������γ�ѭ������)
//1,1,2,0,2,2,1,0;
//��������
#include<iostream>
using namespace std;

int main()
{
	int num;
    int Fibonacci[8]={1,1,2,0,2,2,1,0};
	while(cin>>num)
	{
     // cout<<(num+1)%8<<" "<<Fibonacci[(num+1)%8]<<endl;
		if(Fibonacci[(num+1)%8]==0)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
		//cout<<Fibonacci[(num+1)%9]<<endl;
	

	}
	return 0;
}
