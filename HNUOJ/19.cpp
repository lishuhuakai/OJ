#include <iostream>
#include <string>
using namespace std;
static int counter = 0;
int main()
{
	int numOfCases = 0;
	cin >> numOfCases; // ���Ե�������Ŀ
	int a, b, c;
	for (int i = 0; i < numOfCases; ++i)
	{
		cin >> a >> b >> c;
		string flag = a + b > c ? "true" : "false";
		cout << "Case #" << ++counter << ": " << flag << endl;
	}
	//system("pause");
	return 0;
}