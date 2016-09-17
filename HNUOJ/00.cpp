#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 动态规划的问题，属于很简单的一道题目
 */

int main()
{
	int height_of_tower;
	vector<int> tower;

	int num_of_num = (1 + 100) * 100 / 2;
	tower.reserve(num_of_num + 1); //事先分配好足够的内存
	int temp;

	
	cin >> height_of_tower;
	num_of_num = (1 + height_of_tower) * height_of_tower / 2;
	tower.push_back(0); //tower[0] = 0,不使用
	for (int i = 1; i <= num_of_num; ++i)
	{
		cin >> temp;
		tower.push_back(temp);
	}
	vector<int> value(tower.begin(), tower.end());
	vector<int> index(tower.size());
	/** 
	 * 开始dp,从倒数第一行开始，求从这个点出发，可以获得的最大的价值。
	 */
	for (int j = num_of_num - height_of_tower, n = height_of_tower, i = 0; j > 0; --j)
	{
		int lidx = j + n - 1;
		int ridx = j + n;
		int max;
		if (value[lidx] > value[ridx]) {
			index[j] = lidx;
			max = value[lidx];
		}
		else {
			index[j] = ridx;
			max = value[ridx];
		}
		value[j] = max + value[j]; //基本上是状态转移方程
		if (++i == n - 1)
		{
			--n;
			i = 0;
		}
	}
	cout << value[1] << endl;
	int trace = 1;
	cout << tower[1];
	for (int i = 0; i < height_of_tower - 1; ++i) {
		trace = index[trace];
		cout << " " << tower[trace];
	}
	cout << endl;
	tower.clear();
	//system("pause");
	return 0;
}