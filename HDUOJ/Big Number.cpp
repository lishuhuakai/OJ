//��������ù�ʽ����AC,���ݹ�ģ̫����  
//Stirling��ʽ:    n! = ((2*pi*n)^(1/2))*((n/e)^n); ǰ����n > 3  
//�ɴ˿��Ե���lg(n!)=(lg(2*pi)+lg(n))/2 + n*(lg(n)-lg(e));   
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
	long double c3;//�ر�Ҫע�⾫�ȵ����⣬�˴�c3ӦΪlong double�ͣ���������׶�ʧ���ȣ���ɴ𰸴���
	for(int i=0;i<t;i++)
	{
		cin>>n;
		c3=log10((double)n);
		if(t>3)
			s=(c3+c1)/2+n*(c3-c2)+1;//����10^0=1��10^1=10�������������Ҫ��һ��1
               //s=�������Զ�����ת������10^2.5=x,��s=2+1����˵��x������10^2��10^3֮�䣬λ��Ϊ3��
	else
			s=1;
		cout<<s<<endl;
	}
    return 0;
}


