#include <iostream>
#include <cstring>
using namespace std;
const int SIZE = 1024;
static char test[1024];

int openPresent(char *str)
{
	int numOfLParen = 0; /*左括号和右括号的数目*/
	int numOfRParen = 0;
	int slen = strlen(str);
	for (int i = 0; i < slen; ++i)
	{
		if (str[i] == '(')
			numOfLParen++;
		else if (str[i] == ')')
			numOfRParen++;
		else if (str[i] == 'B')
			break;
	}
	return numOfLParen - numOfRParen;
}

int main()
{
	while (cin >> test)
	{
		cout << openPresent(test) << endl;
	}
	//system("pause");
	return 0;
}