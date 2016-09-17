#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_NUM = 1000001;
int mark[MAX_NUM] = { 0 };

int main()
{
	int n, m;
	string buf;
	char temp[10];
	for (int i = 1; i <= MAX_NUM; ++i)
	{

		buf = _itoa(i, temp, 10);
		if (buf.find_first_of("4") != string::npos || /*没找到4*/
			buf.find("62") != string::npos)//没找到4和62
			continue;
		mark[i] = 1;
	}

	while (cin >> n >> m && !(n == 0 && m == 0))
	{
		
		int count = 0;	
		for (int i = n; i <= m; ++i)
		{
			if (mark[i] == 1)
				++count;
		}
		cout << count << endl;
	}
	return 0;
}