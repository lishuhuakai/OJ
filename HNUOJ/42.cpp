#include<iostream>
using namespace std;
static char names[1024][1024];
/*һ���������Ŀ��û������˼*/
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
		if (numOfNames % 2 == 1) /*������ֵ���ĿΪ������*/
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