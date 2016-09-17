#include <iostream>
#include <algorithm>
using namespace std;
/*��ʵ�Ƿǳ��򵥵�һ������*/
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
		return l.month < r.month; /*�·�С������ǰ��*/
	else if (l.day != r.day)
		return l.day < r.day; /*����С������ǰ��*/
	else
		return l.order < r.order; /*���������˳������*/
		
}
int main()
{
	int numOfStu;
	cin >> numOfStu;
	for (int i = 0; i < numOfStu; ++i)
	{
		cin >> buf[i].id;
		cin >> buf[i].month >> buf[i].day;
		buf[i].order = i; /*��¼��˳��*/
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