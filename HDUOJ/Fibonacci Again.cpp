//Fibonacci Again!这道题目具有很强的规律性！
//我们将各个数列的除3的余数摆出来，一看就知道了！
//  1,2,0,2,2,1,0;(除3余1的数加上除3余2的数相加，和一定除3取0……)
//1,1,2,0,2,2,1,0;(按照这个道理，可以形成循环！！)
//1,1,2,0,2,2,1,0;
//…………
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
