#include<iostream>
using namespace std;
const int MAX=130;
int c1[MAX],c2[MAX];//������������ 
//����c1[n]���浱ǰ����n�ܱ���ֵ��ܷ�����
//������c2Ϊ�м������𵽹��ɵ����� 
int main()
{
	int i,j,k;
	int num;
	while(cin>>num && num>0)//����num,����n�ж����ֲ�ַ����� 
	{
		for(i=0;i<=num;i++)//��ʼ�� 
		{
			c1[i]=1;
			c2[i]=0;
		}
		for(i=2;i<=num;i++)
		{
			for(k=0;k<=num;k++)
				for(j=0;j+k<=num;j=j+i)
				c2[k+j]=c2[k+j]+c1[k];
			for(k=0;k<=num;k++)
			{
				c1[k]=c2[k];
				c2[k]=0;
			}
		}
		cout<<c1[num]<<endl;
	}
	return 0;
}
