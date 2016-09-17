#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char collect[1024];
char needed[1024];
/*题目其实非常简单！用set就可以解决了！*/
int main()
{
	cin >> collect;
	cin >> needed;

	int num_remaind = 0;
	int num_missing = 0;

	int c_index = 0;
	int n_index = 0;

	int c_len = strlen(collect);
	int n_len = strlen(needed);
	sort(collect, collect + c_len);
	sort(needed, needed + n_len);
	
	while (true)
	{
		if (n_len <= n_index)
		{
			num_remaind += (c_len - c_index);
			break;
		}
		if (c_index >= c_len)
		{
			num_missing += (n_len - n_index);
			break;
		}
		if (collect[c_index] > needed[n_index])
		{
			n_index++;
			num_missing++;
		}
		else if (collect[c_index] < needed[n_index])
		{
			c_index++;
			num_remaind++;
			
		}
		else
		{
			c_index++;
			n_index++;
		}
	}
	if (num_missing > 0)
		cout << "No " << num_missing << endl;
	else
		cout << "Yes " << num_remaind << endl;
	//system("pause");
	return 0;
}