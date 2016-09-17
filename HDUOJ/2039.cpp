#include <iostream>
using namespace std;

int main()
{
	int m;
	double n1, n2, n3;
	cin >> m;
	while (m--)
	{
		cin >> n1 >> n2 >> n3; //输入三条边的长度
		if ((n1 + n2 > n3) &&
			(n1 + n3 > n2) &&
			(n2 + n3 > n1))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
