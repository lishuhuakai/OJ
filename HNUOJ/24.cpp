#include <iostream>
#include <cstring>
using namespace std;

static char buf[1024];
static int statistic[10]; /*统计的数据*/
int main()
{
	cin >> buf;
	int len = strlen(buf);
	for (int i = 0; i < len; ++i)
	{
		statistic[buf[i] - '0'] += 1;
	}
	for (int i = 0; i < 10; ++i)
	{
		if (statistic[i] != 0)
			cout << i << ":" << statistic[i] << endl;
	}
	//system("pause");
	return 0;
}