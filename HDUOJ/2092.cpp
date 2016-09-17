#include <iostream>
using namespace std;

int main()
{
	double n = 0, m = 0;
	while (cin >> n >> m && !(n == 0 && m == 0))
	{
		double temp = n * n - 4 * m;
		double c = sqrt(temp);
		double d = floor(c);

		if (temp < 0 || (c - d) != 0) //开方后必须是一个整数
		{
			cout << "No" << endl;
			continue;
		}
		else
		{
			double a = ((-n) + c) / 2;
			double b = floor(a);
			//int b = ((-n) - c) / 2;
			if ((a - b) == 0)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
		
	}
	return 0;
}