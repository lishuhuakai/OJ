#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

static int component[1024];

int first_not_zero(int *array)
{ /*找到第一个不为0的数的下标*/
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
	sort(component, component + counter); /*先排序再说*/
	int pos = first_not_zero(component); 
	cout << component[pos]; /*先输出第一个不为0的数*/
	for (int i = 0; i < pos; ++i) /*其余的依次输出即可*/
		cout << component[i];
	for (int i = pos + 1; i < counter; ++i)
		cout << component[i];
	cout << endl;
	//system("pause");
	return 0;
}