#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 10;
const int MAX = 999;
static int num[SIZE];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	/* 先来排一下序吧 */
	sort(num, num + n); /*默认是从小到大排序的*/
	int max = num[n - 1]; 
	int min = num[0];
	int res = 0;
	int mindist = MAX; /*最小的距离*/
	for (int i = 0; i < n; ++i)
	{
		int distance = abs(abs(num[i] - max) - (num[i] - min));
		if (distance < mindist)
		{
			res = num[i]; /*记录下距离差最小的值*/
			mindist = distance;
		}
			
	}
	cout << res << endl;
	//system("pause");
	return 0;
}