#include <iostream>
using namespace std;

int fn(int n, int m) /*��Ҫע����ǣ�����ı�Ŵ�0��ʼ*/
{
	if (n == 1) return 0; /*���ֻ��һ���ˣ���ô���һ����̭���˵ı��Ϊ1*/
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
		cout << fn(n, m) + 1 << endl; /*��������Ҫ��1*/
	}

	//system("pause");
	return 0;
}