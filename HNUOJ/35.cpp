#include <iostream>
#include <algorithm>
using namespace std;
/*其实是非常简单的一件事情*/
typedef struct STUINFO {
	char id[36];
	int month;
	int day;
	int order;
} stuinfo;

stuinfo buf[1024];
bool cmp(const stuinfo &l, const stuinfo &r)
{
	if (l.month != r.month)
		return l.month < r.month; /*月份小的排在前面*/
	else if (l.day != r.day)
		return l.day < r.day; /*天数小的排在前面*/
	else
		return l.order < r.order; /*按照输入的顺序来排*/
		
}
int main()
{
	int numOfStu;
	cin >> numOfStu;
	for (int i = 0; i < numOfStu; ++i)
	{
		cin >> buf[i].id;
		cin >> buf[i].month >> buf[i].day;
		buf[i].order = i; /*记录下顺序*/
	}
	sort(buf, buf + numOfStu, cmp);
	int month = buf[0].month;
	int day = buf[0].day;
	cout << month << " " << day << " " << buf[0].id;
	for (int i = 1; i < numOfStu; ++i)
	{
		if (month != buf[i].month && day != buf[i].day)
		{
			cout << endl;
			month = buf[i].month;
			day = buf[i].day;
			cout << month << " " << day << " " << buf[i].id;
		}
		else
			cout << " " << buf[i].id;
	}
	cout << endl;
	//system("pause");
	return 0;
}