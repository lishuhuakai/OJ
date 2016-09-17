#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 1024;
static int buf[SIZE];

int main()
{
	int numOfInput, numOfOutput;
	cin >> numOfInput >> numOfOutput;
	for (int i = 0; i < numOfInput; ++i)
	{
		cin >> buf[i];
	}
	sort(buf, buf + numOfInput);
	for (int i = 0; i < numOfOutput - 1; ++i)
	{
		cout << buf[i] << " ";
	}
	cout << buf[numOfOutput - 1] << endl;
	//system("pause");
	return 0;
}