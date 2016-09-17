#include <iostream>
using namespace std;

int fn(int n, int m) /*需要注意的是，这里的编号从0开始*/
{
	if (n == 1) return 0; /*如果只有一个人，那么最后一个淘汰的人的编号为1*/
	else
		return (fn(n - 1, m) + m) % n;
}
int main()
{
	int m, n;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
		cout << fn(n, m) + 1 << endl; /*所以这里要加1*/
	}

	//system("pause");
	return 0;
}