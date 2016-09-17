#include <iostream>
#include <cstring>
using namespace std;
/*ʵ��26���Ƶļ�����*/
const int SIZE = 1024;
static char memoA[SIZE];
static char memoB[SIZE];
static char memoC[SIZE]; /*�����洢����Ľ��*/

char* calc(char *a, char *b)
{
	int curPosOfA = strlen(a) - 1;
	int curPosOfB = strlen(b) - 1; /*����ָ�붼ָ�ڵ�λ*/
	int curPosOfRes = 0; /*�����λ��*/
	int curry = 0; /*��λ*/
	int sum = 0;
	for (;curPosOfA >= 0 && curPosOfB >= 0; curPosOfA--, curPosOfB--)
	{
		sum = (a[curPosOfA] - 'a') + (b[curPosOfB] - 'a') + curry; 
		curry = sum / 26; /*�µĽ�λ*/
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