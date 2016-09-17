#include <iostream>
using namespace std;

int qh_num(int a)//该函数主要用来获得数a的亲和数
{
	int sum = 0;
	for(int i = 1; i <= (int)a / 2; ++i)
	{
		if (a % i == 0)
			sum += i;
	}
	return sum;
}
int main()
{
	int m;
	int a, b;
	cin >> m;
	while (m--)
	{
		cin >> a >> b;
		int qh_a = qh_num(a);
		//cout << qh_a << endl;
		int qh_b = qh_num(b);
		//cout << qh_b << endl;
		if (qh_a == b && qh_b == a)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
