#include<iostream>
using namespace std;
static char names[1024][1024];
/*一道输出的题目，没多少意思*/
int main()
{
	int numOfNames;
	static int counter = 1;
	while (cin >> numOfNames)
	{
		if (numOfNames == 0)
			break;
		for (int i = 0; i < numOfNames; ++i)
		{
			cin >> names[i];
		}
		cout << "set-" << counter++ << endl;
		int index = 0;
		for (; index < numOfNames; index += 2)
		{
			cout << names[index] << endl;
		}
		if (numOfNames % 2 == 1) /*如果名字的数目为奇数个*/
			index = numOfNames - 2;
		else
			index = numOfNames - 1;
		for ( ; index > 0; index -= 2)
		{
			cout << names[index] << endl;
		}
			
	}
	//system("pause");
	return 0;
}