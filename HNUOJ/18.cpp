#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

static char buf[1024];

int main()
{
	gets_s(buf, 1024);
	int len = strlen(buf); // get the length of buffer

	int counter = len - 1;
	char* p = &buf[counter];

	for ( ; ; )
	{
		while (*p != ' ')
		{
			--p; 
			--counter;
			if (counter < 0)
				goto end;
		}
		cout << (p + 1) << *p;
		*p = '\0';
	}
end:
	cout << buf << endl;
	system("pause");
	return 0;
}
