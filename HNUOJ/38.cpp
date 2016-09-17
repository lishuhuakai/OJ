#include <iostream>
using namespace std;

int sumOfDivisor(int num) /*计算num的真约数的和*/
{
	int res = 0;
	for (int i = 1; i <= num / 2; ++i)
	{
		if (num % i == 0)
			res += i;
	}
	return res;
}
int main()
{
	int numOfLine;
	int a, b;
	cin >> numOfLine;
	for (int i = 0; i < numOfLine; ++i)
	{
		cin >> a >> b;
		if ((sumOfDivisor(a) == b) && (sumOfDivisor(b) == a))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	//system("pause");
	return 0;
}