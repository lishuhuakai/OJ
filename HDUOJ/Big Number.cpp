//此题必须用公式才能AC,数据规模太大了  
//Stirling公式:    n! = ((2*pi*n)^(1/2))*((n/e)^n); 前提是n > 3  
//由此可以导出lg(n!)=(lg(2*pi)+lg(n))/2 + n*(lg(n)-lg(e));   
#include<iostream>
#include<cmath>
using namespace std;
const long double c1=0.798179868358; //lg(2*pi)
const long double c2=0.434294481903; //lg(e) 

int main()
{
	int n,t;
	cin>>t;
	int s;
	long double c3;//特别要注意精度的问题，此处c3应为long double型，否则很容易丢失精度，造成答案错误
	for(int i=0;i<t;i++)
	{
		cin>>n;
		c3=log10((double)n);
		if(t>3)
			s=(c3+c1)/2+n*(c3-c2)+1;//由于10^0=1，10^1=10……，故在最后还要加一个1
               //s=？发生自动类型转换，如10^2.5=x,则s=2+1，则说明x！介于10^2与10^3之间，位数为3！
	else
			s=1;
		cout<<s<<endl;
	}
    return 0;
}


