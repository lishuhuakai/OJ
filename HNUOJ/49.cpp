#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
static char buf[1024];
static char input[1024];
static int _index[10];
queue<string> que;

char dict[10][2] = {
	 "0", "1", "2", "3", "4",
	 "5", "6", "7", "8", "9"
};

void handle1(char c)
{
	int num = c - '0'; /*得到牌的大小*/
	
	for (int i = num + 1; i < 10; ++i)
	{
		if (_index[i] != -1)
		{
			string res = dict[i];
			que.push(res); // 将答案压栈
		}	
	}
}

void handle2(char *str, int len)
{
	int num = *str - '0'; /*处理两张一样的牌*/
	for (int i = num + 1; i < 10; ++i)
	{
		if (_index[i] != -1)
		{
			int next_index = _index[i] + 1;
			if ((next_index < len) && (buf[_index[i]] == buf[next_index]))
			{
				string res = dict[i];
				res += dict[i];
				que.push(res);
			}
		}
	}
}

void handle3(char *str, int len)
{
	int num = *str - '0'; /*处理两张一样的牌*/
	for (int i = num + 1; i < 10; ++i)
	{
		if (_index[i] != -1)
		{
			int index1 = _index[i] + 1;
			int index2 = _index[i] + 2;
			if ((index1 < len) && (index2 < len) &&
				(buf[_index[i]] == buf[index1]) && 
				(buf[index1] == buf[index2])) /*妈蛋，我还要保证不能越界*/
			{
				string res = dict[i];
				res += dict[i]; 
				res += dict[i];
				que.push(res);
			}
		}
	}
}

void handle4(char *str, int len)
{
	int num = *str - '0'; /*处理两张一样的牌*/
	for (int i = num + 1; i < 10; ++i)
	{
		if (_index[i] != -1)
		{
			int index1 = _index[i] + 1;
			int index2 = _index[i] + 2;
			int index3 = _index[i] + 3;
			if ((index1 < len) && (index2 < len) && (index3 < len) &&
				(buf[_index[i]] == buf[index1]) && 
				(buf[index1] == buf[index2])
				&& (buf[index2] == buf[index3])) /*妈蛋，我还要保证不能越界*/
			{
				string res = dict[i];
				res += dict[i];
				res += dict[i];
				res += dict[i];
				que.push(res);
			}
		}
	}
}

void handle5(char *str, int len)
{
	int num = *str - '0'; /*得到起始的牌*/
	for (int i = num + 1; i < 6; ++i)
	{
		if (_index[i] != -1)
		{
			string res = dict[i];
			bool flag = false;
			for (int j = i + 1; j < i + 5; j++)
			{
				if (_index[j] != -1)
				{
					res += dict[j];
				}
				else
				{
					res.clear();
					flag = true;
					break;
				}
			}
			if (!flag)
				que.push(res);
		}
	}
}

void Judge(char* input, int i_len, char* buf, int b_len)
{
	switch (i_len)
	{
	case 1:
		handle1(*input);
		break;
	case 2:
		handle2(input, b_len);
		break;
	case 3:
		handle3(input, b_len);
		break;
	case 4:
		handle4(input, b_len);
		break;
	case 5:
		handle5(input, b_len);
		break;
	default:
		break;
	}
}

int main()
{
	cin >> buf;
	int len = strlen(buf);
	sort(buf, buf + len); /*一切等排完序之后再说*/

	int counter = 0;
	_index[0] = -1;
	for (int i = 1; i < 10; ++i)
	{
		_index[i] = -1; /*这算是初始化吧！*/
		char dig = i + '0';
		if (buf[counter] == dig)
			_index[i] = counter; /*记录下数字起始的位置*/
		while (buf[++counter] == dig && counter < len);
	}

	while (cin >> input)
	{
		int i_len = strlen(input); /*得到长度*/
		Judge(input, i_len, buf, len);
		if (que.empty())
			cout << "NO" << endl;
		else
		{
			cout << "YES";
			while (!que.empty())
			{
				string res = que.front();
				cout << " " << res.c_str();
				que.pop();
			}
			cout << endl;
		}
	}
	//system("pause");
	return 0;
}