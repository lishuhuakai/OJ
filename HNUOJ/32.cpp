#include <iostream>
using namespace std;
int buf[100][100];

int main()
{
	int n;
	cin >> n;
	// 题目无非就是要构造一个三角形，是吧！
	/*先构造出第一排*/
	buf[1][1] = 1;
	for (int i = 2; i <= n; ++i)
		buf[1][i] = buf[1][i - 1] + i;
	/*然后竖着构造*/
	int dy = 0;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= n - i + 1; j++)
			buf[i][j] = buf[i - 1][j] + dy + j;
		dy++;
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << buf[i][1];
		for (int j = 2; j <= n - i + 1; ++j)
		{
			cout << " " << buf[i][j];
		}
		cout << endl;
	}
	//system("pause");
	return 0;
}