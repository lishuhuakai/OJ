#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZE = 1024;
static char output[SIZE];

bool isletter(char c)
{
	if (c >= 'A' && c <= 'Z')
		return true;
	else
		return false;
}

int main()
{
	char input[SIZE];
	char buf[SIZE];
	gets(input);
	strcpy(buf, input); // backup
	int slen = strlen(input);
	sort(input, input + slen); // ������ĸ��ASCII���еĴ�������
	int oidx = 0; // output index
	int iidx = 0; // input index
	int bidx = 0; // buf index
	/**������Ҫ˵һ�䣬��ΪA-Z��ASCII�����������ģ���������������е�A��Z����ĸ��input��Ҳ��������
	���ԣ��ҳԵ�ǰ��Ĳ���A-Z���ַ�*/
	while (!isletter(input[iidx])) ++iidx;
	for (; oidx < slen; ++oidx)
	{
		if (isletter(buf[oidx]))
			output[oidx] = input[iidx++];
		else
			output[oidx] = buf[oidx];
	}
	output[slen] = '\0';
	cout << output << endl;

	system("pause");
	return 0;
}