#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int SIZE = 1024;
static char input_a[SIZE];
static char input_b[SIZE];

int counter(char* str, char c) /*���ڼ���*/
{
	int res = 0;
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == c)
			++res;
	}
	return res;
}

int getPartNum(char c, int n) /*���ڵõ���Ӧ��intֵ*/
{
	int i = c - '0';
	int res = 0;
	for (n = n - 1; n >= 0; --n)
	{
		res += i * pow(10, n);
	}
	return res;
}

int main()
{
	char da, db;
	cin >> input_a >> da >> input_b >> db;
	int dac = counter(input_a, da); // ͳ���ַ����ֵĴ���
	int dbc = counter(input_b, db);
	cout << getPartNum(da, dac) + getPartNum(db, dbc) << endl;
	//system("pause");
	return 0;
}