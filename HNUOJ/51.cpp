#include <iostream>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
	string curse;
	string explain;
	string input;
	map<string, string> cur2ex;
	map<string, string> ex2cur;
	int numOfTest;
	while (cin >> curse)
	{
		if (curse == "@END@")
			break;
		getline(cin, explain); /*得到一行输入*/
		int size = explain.find_first_not_of(' ');
		explain = explain.substr(size);
		cur2ex[curse] = explain;
		ex2cur[explain] = curse;
	}
	cin >> numOfTest;
	getchar();
	for (int i = 0; i < numOfTest; ++i)
	{
		getline(cin, input);
		map<string, string>::iterator it;
		it = cur2ex.find(input);
		if (it != cur2ex.end())
		{
			cout << cur2ex[input] << endl;
		}
		else
		{
			it = ex2cur.find(input);
			if (it != ex2cur.end())
			{
				string buf = ex2cur[input];
				buf = buf.substr(1, buf.length() - 2); /*去掉[],仅此而已*/
				cout << buf << endl;
			}
			else
				cout << "what?" << endl;
		}
	}
	//system("pause");
	return 0;
}