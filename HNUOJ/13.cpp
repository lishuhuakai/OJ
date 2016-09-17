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
	sort(input, input + slen); // 按照字母在ASCII表中的次序排序
	int oidx = 0; // output index
	int iidx = 0; // input index
	int bidx = 0; // buf index
	/**这里我要说一句，因为A-Z在ASCII表中是连续的，所以排序完后，所有的A—Z的字母在input中也是连续的
	所以，我吃掉前面的不是A-Z的字符*/
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