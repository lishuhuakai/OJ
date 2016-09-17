#include <iostream>
#include <algorithm>
using namespace std;
/*������Ŀ�������Ǳ�������*/
int bill[20];
bool cmp(int a, int b)
{
	return a > b;
}
int find(int* bill, int kind, int money)
{
	int res = 0;
	for (int i = 0; i < kind; ++i)
	{
		if (bill[i] <= money)
		{
			money -= bill[i];
			res++;
		}
	}
	if (money > 0)
		return -1;
	else
		return res;
}
int main()
{
	int money;
	int kind;
	while (cin >> money)
	{
		if (money == 0)
			break;
		cin >> kind;
		for (int i = 0; i < kind; ++i)
		{
			cin >> bill[i];
		}
		sort(bill, bill + kind, cmp);
		int res = find(bill, kind, money);
		if (res == -1)
			cout << "Impossible" << endl;
		else
			cout << res << endl;
	}
	//system("pause");
	return 0;
}