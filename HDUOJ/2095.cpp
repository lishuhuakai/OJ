/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;

//const int MAX_NUM = 1000000;

int main()
{
	multiset<int> num_set;
	int num;
	while (cin >> num && num != 0)
	{
		//int numOfPresent[MAX_NUM];
		//memset(numOfPresent, 0, sizeof(numOfPresent));
		int present_num;
		num_set.clear();
		for (int i = 0; i < num; ++i)
		{
			scanf("%d", &present_num);
			num_set.insert(present_num);
		}
		multiset<int>::iterator set_it = num_set.begin();

		for (; set_it != num_set.end(); ++set_it)
		{
			if (num_set.count(*set_it) % 2)
			{
				cout << *set_it << endl;
				break;
			}
		}


	}
	return 0;
}
*/
/*使用set不太现实，因为内存会超出限制*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;
const int MAX_NUM = 1000000;
int num_of_present[MAX_NUM];

int main()
{
	map<int, int> num_map;
	
	int num;
	while (cin >> num && num != 0)
	{
		int present_num = 0;
		int index = 0; //指针
		num_map.clear();
		memset(num_of_present, 0, sizeof(num_of_present));
		for (int i = 0; i < num; ++i)
		{
			scanf("%d", &present_num);
			map<int, int>::iterator map_it = num_map.find(present_num);
			if (map_it != num_map.end())
			{
				++num_of_present[map_it->second];
				//cout << "要插入的数字是" << present_num << endl;
				//cout << "map_it->second = " << map_it->second << endl;
				//cout << "num_of_present[map_it->second] = " << num_of_present[map_it->second] << endl;
			}
			else
			{
				//cout << "要插入的数字是" << present_num << endl;
				//cout << "map中无数据" << endl;
				//cout << "index = " << index << endl;
				num_map.insert(make_pair(present_num, index));
				++num_of_present[index];
				++index;
			}

		}
		map<int, int>::iterator map_it = num_map.begin();
		while (map_it != num_map.end())
		{
			if (num_of_present[map_it->second] % 2 != 0)
			{
				cout << map_it->first << endl;
				break;
			}
			++map_it;
		}
		
	}
	return 0;
}