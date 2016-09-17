/**************************
��������������ķǵݹ��㷨������������ԣ����У�
ģ��next_permutation������

˵��һ�㣬�� 1��2��3��4 ���� a��b��c��d�����Եõ���

ԭ����                  �м�ת��                ֵ
1��2��3��4        3��2��1            ((3 * (3) + 2) * (2) + 1) * (1) = 23
1��2��4��3        3��2��0            ((3 * (3) + 2) * (2) + 0) * (1) = 22
1��3��2��4        3��1��1            ((3 * (3) + 1) * (2) + 1) * (1) = 21
1��3��4��2        3��1��0            ((3 * (3) + 1) * (2) + 0) * (1) = 20
1��4��3��2        3��0��1            ((3 * (3) + 0) * (2) + 1) * (1) = 19
.                  .                     .
.                  .                     .
.                  .                     .
4��3��2��1        0��0��0            ((0 * (3) + 0) * (2) + 0) * (1) = 0
                              
 ������м�ת��ָ���ǣ�ÿһ�����ֺ���ȵ�ǰλ���ִ�����ֵĸ��������磺

1��3��4��2  �У�1 ������(3, 4, 2) ���Ƕ�����1�����Ե�һλ�� 3
                              3 ������(4, 2), ��ֻ��4����3�����Եڶ�λ�� 1
                              4 ������(2), û�б�4 ��ģ����Ե���λ�� 0
                              ���һλ����϶�û�и���ģ�����ʡ����һ��0��

��������ת���Ժ󣬾͵õ���һ�ֱ�ʾ��ʽ���м�ת���������ֱ��﷽ʽ��ԭ����һһ��Ӧ�������໥ת����

��ϸ�۲������м���﷽ʽ���������ĵ�һλֻ���ǣ�0��1��2��3�����ڶ�λֻ���ǣ�0��1��2��������λֻ���ǣ�0��1����
ͨ������������ʮ���Ʊ�ʾ�ģ���������ö����ƣ��������ڣ�����һ������Ľ�������ʾ����

��һλ��1���ƣ��ڶ�λ��2���ơ�����

���Ǿ͵õ��������м��ʾ��ʽ��ʮ����ֵ���磺

                                     ��                  
                          |          |          |
1��1��0    ---->   ((1 * (3) + 1) * (2) + 0) * (1) = 8

3��1��0    ---->   ((3 * (3) + 1) * (2) + 0) * (1) = 20

�������Ϳ��Եõ�һ��ʮ��������һ������֮���һһ��Ӧ�Ĺ�ϵ��
�����������������ʮ����������һһ��Ӧ�Ĺ�ϵ��ͨ���ı��Ӧ��ϵ������ʹʮ���������򣩡�
�������Ѿ����Ժ����׵ĵõ�����һ��������;
��������Ķ�Ӧ��ϵ��һ�����ܵ�ȡֵ��(���λ��ȡ�ĸ�ֵ,��λȡ3��'''')4*3*2*1=24�֣�
�������ʵֻ��һ����ʽ���ˣ�Ϊ�˱�������������ģ��
**************************/
#include<iostream>
using namespace std;
const MAX=50;
int a[MAX];

int permutation(int n)//���к���
{
	int i,j,tmp,flag=1;
	for(i=n;i>=2 && flag/*��һ����ѧ�ģ����Է�����˳�����ѭ��*/;i--)
		if(a[i]>a[i-1])//�����ÿ���ڵ��������бȽϣ������ǰ��һ���Ⱥ����С��iΪ��Сλ�ã�ii,Ϊ�ϴ�λ�ã�����ô��ʱһ������һ�����бȵ�ǰ�Ĵ�
		{
			for(j=n;j>=2 && flag;j--)//Ӧ���������С�����ĺ�������ʼ������ĵ�һ����
			{
				if(a[j]>a[i-1])//����������ǰ��С��λ����
				{
					tmp=a[j]; a[j]=a[i-1]; a[i-1]=tmp; flag=0/*�ҵ����������������൱���ҵ���һ�����У��Ϳ��Է�����*/;
				}
			}
			if(!flag)//�ϴ���ii������������,�������������Ͳ�������һ�����У�ԭ�������ڣ��ҵ���һ���ϴ����Ϊ��ʼλ������Ȼ�󽫺�������ִ���С��ʼ������
			{
				tmp=a[i];  a[i]=a[n]; a[n]=tmp;/*��������ʵ�����ǽ����е���������������ķ�ʽ��1*/
			}//�����������ʱ���㲻��������
		}
	if(flag) return 0;
	else return 1;
}
int main(int argc, char *argv[])
{
	int n,i;
	while(1)
	{
		cin>>n;
		for(i=1;i<50;i++) a[i]=i;
		do
		{
			for(i=1;i<=n;i++) cout<<a[i]<<"  ";
			cout<<endl;
		}while (permutation(n));//һֱ�������У�ֱ��������<��������ķ�ʽ>(���Ӵ�С)��Ϊ0��
		
	}
	return 0;
}