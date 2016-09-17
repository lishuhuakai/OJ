/*空心三角形
 *很水，真的，我都不愿意拿这种题目来写博客了！
 */

#include <iostream>
using namespace std;
void print_x(char c, int n, int index1, int index2)
{
	if (index2 == n)
	{
		for (int i = 1; i <= n; ++i)
			cout << c;
	}
	else
	{
		for (int i = 1; i <= index2; ++i)
		{
			if (i == index1 || i == index2)
				cout << c;
			else
				cout << ' ';
		}
	}
	cout << endl;
}
int main()
{
	int n = 0;
	int index1 = 0;
	int index2 = 0;
	char c = ' ';
	bool is_first_tri = true; //是否为第一个三角形
	while (cin >> c && c != '@')
	{
		cin >> n;
		if (!is_first_tri)
			cout << endl;
		
		index1 = index2 = (2 * n - 1) / 2 + 1;
		while (index1 >= 1 && index2 <= 2 * n - 1)
		{
			print_x(c, 2 * n - 1, index1, index2);
			index1 -= 1;
			index2 += 1;
		}
		
		is_first_tri = false;
	}
	return 0;
}

