#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	string name_of_food;
	double num, unit_price;
	double sum = 0;
	while (cin >> name_of_food)
	{
		cin >> num >> unit_price;
		sum += num * unit_price;
	}
	cout << setiosflags(ios::fixed) << setprecision(1) << sum << endl;
	system("pause");
	return 0;
}