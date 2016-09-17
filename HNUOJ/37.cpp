#include <iostream>
#include <cstring>
using namespace std;
/*模拟计算器的运行*/
static int registerR1;
static int registerR2;
static int registerR3;
static int memoM1;
static int memoM2;
static char command[1024]; /*to memeorize the command*/

void commandA()
{
	registerR1 = memoM1;
}

void commandB()
{
	registerR2 = memoM2;
}

void commandC()
{
	memoM1 = registerR3; 
}

void commandD()
{
	memoM2 = registerR3;
}

void commandE()
{
	registerR3 = registerR1 + registerR2;
}

void commandF()
{
	registerR3 = registerR1 - registerR2;
}

int main()
{
	while (cin >> memoM1)
	{
		cin >> memoM2;
		cin >> command;
		int clen = strlen(command); /*指令的长度*/
		for (int j = 0; j < clen; ++j)
		{
			switch (command[j]) {
			case 'A': commandA(); break;
			case 'B': commandB(); break;
			case 'C': commandC(); break;
			case 'D': commandD(); break;
			case 'E': commandE(); break;
			case 'F': commandF(); break;
			}
		}
		cout << memoM1 << "," << memoM2 << endl;
	}
	//system("pause");
	return 0;
}