#include <iostream>

using namespace std;

int main()
{
	int num;
	int num_a, num_b;
	int sum;
	cin >> num;
	++num;
	while (--num)
	{
		cin >> num_a >> num_b;
		num_a %= 100;
		num_b %= 100;
		sum = (num_a + num_b) % 100;
		cout << sum << endl;
	}
	return 0;
}

