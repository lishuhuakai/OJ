#include <iostream>
#include <cstring>
using namespace std;
static char buf[1024];
static char dict[10][5] = {
	"ling", "yi", "er",
	"san", "si",  "wu",
	"liu", "qi", "ba",
	"jiu"
};

void print(int n)
{
	int stk[1024] = { 0 };
	int index = 0;
	while (n != 0) {
		stk[index++] = n % 10;
		n = n / 10;
	}
	for (int i = index - 1; i > 0; --i)
		cout << dict[stk[i]] << " ";
	cout << dict[stk[0]] << endl;
}

int main()
{
	cin >> buf;
	int len = strlen(buf);
	int sum = 0;
	for (int i = 0; i < len; ++i)
	{
		sum += buf[i] - '0';
	}
	print(sum);
	//system("pause");
	return 0;
}