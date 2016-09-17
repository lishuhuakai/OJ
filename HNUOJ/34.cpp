#include <iostream>
using namespace std;

bool is_seven_times(int val) /*�ж�һ�����Ƿ�Ϊ7�ı���*/
{
	if ((val >= 7) && (val % 7 == 0))
		return true;
	else
		return false;
}

bool digit_contain_seven(int val) /*�ж����Ƿ������7*/
{
	int remain = val % 10; /*����*/
	int quoent = val / 10; /*��*/
	while (quoent != 0)
	{
		if (remain == 7) return true;
		else
		{
			remain = quoent % 10;
			quoent = quoent / 10;
		}
	}
	return false;
}

static int res[30000];
int main()
{
	int num;
	cin >> num;
	int index = 0;
	for (int i = 7; i <= num; ++i)
	{
		if (is_seven_times(i) || digit_contain_seven(i))
			res[index++] = i;
	}
	for (int i = 0; i < index; ++i)
		cout << res[i] << endl;
	//system("pause");
	return 0;
}