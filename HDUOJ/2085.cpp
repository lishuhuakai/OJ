#include <iostream>
using namespace std;

int main()
{
	int n;
	int sec;
	while (cin >> n && n != -1)
	{
		//cin >> sec; // ‰»Î∂‡…Ÿ√Î
		__int64 sum_of_high = 1;
		__int64 sum_of_low = 0;
		__int64 high_temp = sum_of_high;
		__int64 low_temp = sum_of_low;

		for (int i = 1; i <= n; ++i)
		{
			sum_of_high = 3 * high_temp + 2 * low_temp;
			sum_of_low = high_temp + low_temp;
			high_temp = sum_of_high;
			low_temp = sum_of_low;
		}
		cout << sum_of_high << ", " << sum_of_low << endl;
	}
	return 0;
}