#include<iostream>
using namespace std;

int main()
{
	/*其实很简答，我们可以直接计算出来*/
	int days;
	while (cin >> days)
	{
		int sumOfCoin = 0; /*金币的数目*/
		int remainDays = days;
		for (int i = 1; ; ++i)
		{
			if (remainDays > i)
			{
				remainDays -= i;
				sumOfCoin += i * i;
			}
			else
			{
				sumOfCoin += remainDays * i;
				break;
			}
		}
		cout << days << " " << sumOfCoin << endl;
	}
	//system("pause");
	return 0;
}