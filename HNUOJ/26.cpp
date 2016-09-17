#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

static int component[1024];

int first_not_zero(int *array)
{ /*�ҵ���һ����Ϊ0�������±�*/
	int i = 0;
	while (array[i] == 0)
		i++;
	return i;
}
int main()
{
	int buf;
	int counter = 0;
	while (cin >> buf)
	{
		component[counter++] = buf;
	}
	sort(component, component + counter); /*��������˵*/
	int pos = first_not_zero(component); 
	cout << component[pos]; /*�������һ����Ϊ0����*/
	for (int i = 0; i < pos; ++i) /*����������������*/
		cout << component[i];
	for (int i = pos + 1; i < counter; ++i)
		cout << component[i];
	cout << endl;
	//system("pause");
	return 0;
}