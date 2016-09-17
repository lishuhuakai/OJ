#include <iostream>
#include <cstring>
using namespace std;
/*实现26进制的计算器*/
const int SIZE = 1024;
static char memoA[SIZE];
static char memoB[SIZE];
static char memoC[SIZE]; /*用来存储计算的结果*/

char* calc(char *a, char *b)
{
	int curPosOfA = strlen(a) - 1;
	int curPosOfB = strlen(b) - 1; /*两个指针都指在低位*/
	int curPosOfRes = 0; /*结果的位置*/
	int curry = 0; /*进位*/
	int sum = 0;
	for (;curPosOfA >= 0 && curPosOfB >= 0; curPosOfA--, curPosOfB--)
	{
		sum = (a[curPosOfA] - 'a') + (b[curPosOfB] - 'a') + curry; 
		curry = sum / 26; /*新的进位*/
		memoC[curPosOfRes++] = (sum % 26) + 'a';
	}
	while (curPosOfA >= 0)
	{
		sum = (a[curPosOfA--] - 'a') + curry;
		curry = sum / 26;
		memoC[curPosOfRes++] = (sum % 26) + 'a';
	}
	while (curPosOfB >= 0)
	{
		sum = (b[curPosOfB--] - 'a') + curry;
		curry = sum / 26;
		memoC[curPosOfRes++] = (sum % 26) + 'a';
	}
	memoC[curPosOfRes] = '\0';
	return memoC;
}

void output(char *res)
{
	int len = strlen(res);
	for (int i = len - 1; i >= 0; --i)
	{
		cout << res[i];
	}
	cout << endl;
}

int main()
{
	int lines;
	cin >> lines;
	for (int i = 0; i < lines; ++i)
	{
		cin >> memoA >> memoB;
		output(calc(memoA, memoB));
	}
	//system("pause");
	return 0;
}