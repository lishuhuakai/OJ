//������Ҫ�϶�����������ȷ�� 
//�����Ǵ����˳�������ס��������δ����ģ��������ݺܴ��û����������͸����޷�����Ҫ��ֻ������������ʾ��
//�����˷���10000���Ľ׳�����̫�󣡼������鿪С�˶�������
#include <iostream>
#include<cstdio>
#include<memory.h>
using namespace std;
#define MAX 10000
#define BASE 100000//baseֻ��һ�����ȣ�������ȡֵ��û��Ӱ�죬�෴��baseȡֵ���󣬼�������С
//base�����ı��ʱ����������ҲҪ��Ӧ����������������Ҳ���������𰸣����ǵ�baseȡ10��
int h[MAX];
//�����ҵڶ��νӴ������ĳ˷������ڸ�ϰһ�°ɣ��ܺõ��㷨��

int main()
{
    int i,j,k,carry;
	int n;
    
	while(scanf("%d",&n)!=EOF)
	{  
		memset(h,0,MAX*sizeof(int));//��ֵ��ÿһ������Ϊ0 
		for(i=1,h[MAX-1]=1;i<=n;++i)//���õݹ飬����h[1]=1; 
		for(k=MAX-1,carry=0;k>=0;--k)//�����һλ��ʼ���,������ǰ��ÿһλ��� 
		{ 
			carry+=i*h[k];
			h[k]=carry%BASE;
			carry/=BASE;//carry��ʾ��λ
		}       
		for(j=0;j<MAX && h[j]==0;++j);//��0λ��ʼ�������ҵ���Ϊ0�ĵ�һ���� 
		printf("%d",h[j++]);//�������������ͺ����ˣ���һλ���ܲ�����λ���͵������
        for(;j<MAX;++j)
		printf("%05d",h[j]);//�����м��ֵҲ����û����λ����ʱ��Ҫע���ˣ�����߼�0������5λ����Ȼ�𰸻������	
    	printf("\n");
	}
    //system("pause");
	
    return 0;
}