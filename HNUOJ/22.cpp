#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int judge(char a, char b)
{ /*���������Ҫ�����ж����Ӯ*/
	if (a == b)
		return 0; /*0��ʾƽ��*/
	else if (a == 'C') /*�׳�����*/
	{
		if (b == 'B')
			return -1; /*�ҳ���������*/
		else if (b == 'J')
			return 1;
	}
	else if (a == 'B') /*�׳���*/
	{
		if (b == 'C')
			return 1; /*�ҳ����ӣ���Ӯ*/
		else if (b == 'J')
			return -1;
	}
	else if (a == 'J') /*�ҳ�����*/
	{
		if (b == 'B')
			return 1;
		else if (b == 'C')
			return -1;
	}
	return -2; /*����Ǵ�����*/
}

typedef struct RECORD
{
	int win_t;
	int lose_t;
	int draw_t;
	int win_pose_t[3];
}record;

static record res[2];

int map(char pose) /*map����*/
{
	if (pose == 'B') /*������밴����ĸ���С��������*/
		return 0;
	else if (pose == 'C')
		return 1;
	else
		return 2;
}

char re_map(int index) /*map�����ķ�����*/
{
	if (index == 0) 
		return 'B';
	else if (index == 1)
		return 'C';
	else
		return 'J';
}

int max(int* array, int size) /*�����ֵ*/
{
	int max = -999;
	int res = 0;
	for (int i = 0; i < size; ++i)
	{
		if (array[i] > max)
		{
			max = array[i];
			res = i; /*��ʵ�ҵĹؼ����±꣬�ò��ã�*/
		}
			
	}
	return res;
}

int main()
{
	int times;
	memset(res, 0, sizeof(res));
	cin >> times; /*���뽻��Ĵ���*/
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