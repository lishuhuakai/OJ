#include <iostream>
#include <algorithm>
using namespace std;
static int buf[1024];
/*�������Ե�����*/
int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		cin >> buf[i];
	}
	sort(buf, buf + num); /*������һ��*/
	int counter = 0;
	for (int i = 0; i < num - 1; ++i)
	{
		if (buf[i + 1] - buf[i] == 1)
			counter++;
	}
	cout << counter << endl;
	//system("pause");
	return 0;
}

