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
	/* ������һ����� */
	sort(num, num + n); /*Ĭ���Ǵ�С���������*/
	int max = num[n - 1]; 
	int min = num[0];
	int res = 0;
	int mindist = MAX; /*��С�ľ���*/
	for (int i = 0; i < n; ++i)
	{
		int distance = abs(abs(num[i] - max) - (num[i] - min));
		if (distance < mindist)
		{
			res = num[i]; /*��¼�¾������С��ֵ*/
			mindist = distance;
		}
			
	}
	cout << res << endl;
	//system("pause");
	return 0;
}