#include<iostream>
using namespace std;

int main()
{
	/*��ʵ�ܼ�����ǿ���ֱ�Ӽ������*/
	int days;
	while (cin >> days)
	{
		int sumOfCoin = 0; /*��ҵ���Ŀ*/
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