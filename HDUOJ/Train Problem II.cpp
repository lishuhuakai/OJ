//����������� 
//������Ҫ�϶�����������ȷ�� 
//�����Ǵ����˳�������ס��������δ����ģ��������ݺܴ��û����������͸����޷�����Ҫ��ֻ������������ʾ��
#include <iostream>
#include<cstdio>
#include<memory.h>
using namespace std;
#define MAX 101
#define BASE 10000//baseֻ��һ�����ȣ�������ȡֵ��û��Ӱ�죬�෴��baseȡֵ���󣬼�������С
//base�����ı��ʱ����������ҲҪ��Ӧ����������������Ҳ���������𰸣����ǵ�baseȡ10��
void multiply(int a[],int len,int b)//�˷� 
{
    for(int i=len-1,carry=0;i>=0;--i)//�����һλ��ʼ���,������ǰ��ÿһλ��� 
    {//�������ڣ�ΪʲôBASE=10000�� 
        carry+=b*a[i];
        a[i]=carry%BASE;
        carry/=BASE;
    //cout<<"carry="<<carry<<" "<<"a["<<i<<"]="<<a[i]<<endl;//��4��0Ϊһ��
    } 
}
void divide(int a[],int len,int b)//����������ģ����ֳ��������벻������ϸ��ᣡ 
{//Ӧ����γ��أ�
    for(int i=0,div=0;i<len;++i)//�Ӹ�λ����
    {
        div=div*BASE+a[i];
        a[i]=div/b;//bΪ����
        div%=b;
    }
}
int main()
{
    int i,j,h[101][MAX];
    memset(h[1],0,MAX*sizeof(int));//��ֵ��ÿһ������Ϊ0 
    for(i=2,h[1][MAX-1]=1;i<=100;++i)//���õݹ飬����h[1]=1; 
    {
        memcpy(h[i],h[i-1],MAX*sizeof(int));//h[i]=h[i-1];���ֽڿ�������֤��h[i]��h[i-1]ָ�������һ���� 
        multiply(h[i],MAX,4*i-2);//h[i]*=(4*i-2);
        divide(h[i],MAX,i+1);//h[i]/=(i+1);        
    }//�ݹ�õ�ǰ100��Ŀ���������
    while(cin>>i && i>=1 && i<=100)//����i��ֵ 
    {
                // for(i=1;i<=100;i++)
                // {
        for(j=0;j<MAX && h[i][j]==0;++j);//��0λ��ʼ�������ҵ���Ϊ0�ĵ�һ���� 
		//printf("%d\n",EOF);��c�����У�EOF=-1��
		printf("%d",h[i][j++]);//�������������ͺ����ˣ���һλ���ܲ�����λ���͵������
              for(;j<MAX;++j)
		{
		//	if(h[i][j]==0)
		printf("%04d",h[i][j]);//�����м��ֵҲ����û����λ����ʱ��Ҫע���ˣ�����߼�0������4λ����Ȼ�𰸻������
			//	else
         // printf("%d",h[i][j]);//�������ֵ 
        
       }
    
    	printf("\n");
	}
    system("pause");
	
    return 0;
}