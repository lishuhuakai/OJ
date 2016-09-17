#include <iostream>
using namespace std;
int matrix[512][512];

int main()
{
	int line, clomn; // 行数和列数
	cin >> line >> clomn;
	for (int i = 0; i < line; ++i)
	{
		for (int j = 0; j < clomn; ++j)
		{
			cin >> matrix[i][j];
		}
	}
	/* 接下来只要按照题目的要求来输出结果即可 */
	for (int i = clomn - 1; i >= 0; --i)
	{
		int j = 0;
		for ( ; j < line - 1; ++j)
		{
			cout << matrix[j][i] << " ";
		}
		cout << matrix[j][i] << endl;
	}
	//system("pause");
	return 0;
}