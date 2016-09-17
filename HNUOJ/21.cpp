#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int SIZE = 1024;
static char  dividend[SIZE]; /*������*/
static char quotient[SIZE]; /*��*/
/*
���������Ҫ�����ֶ���ģ�����
*/
int main()
{
	int divisor; /*����*/
	cin >> dividend >> divisor;
	int divid_len = strlen(dividend); /*�õ��������ĳ�����Ϣ*/
	int quot_pos = 0; /*����ָʾ�̵�λ��*/
	int remainder = 0; /*����*/
	for (int i = 0; i < divid_len; ++i)
	{
		remainder *= 10; /*���ֹ�ģ��һ����������һλʱ����λҪ��Ϊ��λ*/
		int highest_part_dvdent = dividend[i] - '0';  /*�����������λ��ֵ*/
		int high_part_dvdent = remainder + highest_part_dvdent; /*�������ĸ�λ��ֵ*/
		if (high_part_dvdent < divisor) /*��������Ҫ��λ*/
		{
			quotient[quot_pos++] = '0';
			remainder = highest_part_dvdent;
		}
		else
		{
			/*���ڿ��������*/
			remainder = high_part_dvdent % divisor; /*�õ�����*/
			quotient[quot_pos++] = (high_part_dvdent / divisor) + '0'; /*ת����Ϊ��*/
		}
	}
	quotient[quot_pos] = '\0';
	/*����Ҫ����һ�����飬���ǲ�Ҫ��ʾ��ǰ���0*/
	char * res = quotient;
	while (*res == '0') res++;
	cout << res << " " << remainder << endl;
	system("pause");
	return 0;
}