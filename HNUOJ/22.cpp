#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int judge(char a, char b)
{ /*这个函数主要用于判断输和赢*/
	if (a == b)
		return 0; /*0表示平局*/
	else if (a == 'C') /*甲出锤子*/
	{
		if (b == 'B')
			return -1; /*乙出布，甲输*/
		else if (b == 'J')
			return 1;
	}
	else if (a == 'B') /*甲出布*/
	{
		if (b == 'C')
			return 1; /*乙出锤子，甲赢*/
		else if (b == 'J')
			return -1;
	}
	else if (a == 'J') /*乙出剪刀*/
	{
		if (b == 'B')
			return 1;
		else if (b == 'C')
			return -1;
	}
	return -2; /*这个是错误码*/
}

typedef struct RECORD
{
	int win_t;
	int lose_t;
	int draw_t;
	int win_pose_t[3];
}record;

static record res[2];

int map(char pose) /*map函数*/
{
	if (pose == 'B') /*这里必须按照字母序从小到大排列*/
		return 0;
	else if (pose == 'C')
		return 1;
	else
		return 2;
}

char re_map(int index) /*map函数的反函数*/
{
	if (index == 0) 
		return 'B';
	else if (index == 1)
		return 'C';
	else
		return 'J';
}

int max(int* array, int size) /*求最大值*/
{
	int max = -999;
	int res = 0;
	for (int i = 0; i < size; ++i)
	{
		if (array[i] > max)
		{
			max = array[i];
			res = i; /*其实我的关键是下标，好不好！*/
		}
			
	}
	return res;
}

int main()
{
	int times;
	memset(res, 0, sizeof(res));
	cin >> times; /*输入交锋的次数*/
	char pose_a, pose_b;
	for (int i = 0; i < times; ++i)
	{
		cin >> pose_a >> pose_b;
		int flag = judge(pose_a, pose_b);
		if (flag == 0)
		{
			res[0].draw_t += 1;
			res[1].draw_t += 1;
		}
		else if (flag == 1)
		{
			res[0].win_t += 1;
			res[1].lose_t += 1;
			res[0].win_pose_t[map(pose_a)] += 1;
		}
		else if (flag == -1)
		{
			res[0].lose_t += 1;
			res[1].win_t += 1;
			res[1].win_pose_t[map(pose_b)] += 1;
		}
	}

	cout << res[0].win_t << " " << res[0].draw_t << " " << res[0].lose_t << endl;
	cout << res[1].win_t << " " << res[1].draw_t << " " << res[1].lose_t << endl;
	cout << re_map(max(res[0].win_pose_t, 3)) << " " << re_map(max(res[1].win_pose_t, 3)) << endl;
	//system("pause");
	return 0;
}