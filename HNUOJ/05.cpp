#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
bool char_match(int flag, char a, char b)
{
	if (flag) /*��Сд����*/
		return a == b;
	else /*��Сд������*/
		return (a == b) || (abs(a - b) == 32);
}

bool match(int flag, char *l, char *r)
{ /* ���������Ҫ��������r�Ƿ�����l��ͷ�� */
	int l_len = strlen(l);
	for (int i = 0; i < l_len; ++i)
	{
		if (!char_match(flag, l[i], r[i]))
			return false;
	}
	return true;
}

bool find(int flag, char *l, char *r)
{
	int l_len = strlen(l);
	int r_len = strlen(r);
	if (r_len < l_len) return false;
	int cmp_times = r_len - l_len + 1; /*��Ҫ�ȽϵĴ���*/
	for (int i = 0; i < cmp_times; ++i)
	{
		if (match(flag, l, &r[i]))
			return true;
	}
	return false;
}
static char buf[1024];
static char input[1024];
int main()
{
	int flag, times;
	cin >> buf >> flag >> times;
	for (int i = 0; i < times; ++i)
	{
		cin >> input;
		if (find(flag, buf, input))
			cout << input << endl;
	}
	//system("pause");
	return 0;
}