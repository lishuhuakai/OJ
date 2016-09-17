#include <iostream>
#include <algorithm>
using namespace std;

typedef struct INFO
{
	int id;
	int grade;
}info;

typedef struct SINFO
{
	int id;
	int grades;
} sinfo;

static info buf[1024];
static sinfo s[1024];
bool cmp(const info &l, const info &r)
{
	return l.id < r.id;
}
bool new_cmp(const sinfo &l, const sinfo &r)
{
	return l.grades > r.grades; /*按照总分从小到大排序*/
}
int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i)
		cin >> buf[i].id >> buf[i].grade;
	sort(buf, buf + num, cmp); /*先按照学校名称排序*/
	int index = 0;
	int sch_id = buf[0].id; /*学校的标记*/
	s[index].id = sch_id;
	for (int i = 0; i < num; ++i)
	{
		if (buf[i].id == sch_id)
			s[index].grades += buf[i].grade;
		else
		{
			sch_id = buf[i].id;
			s[++index].grades = buf[i].grade;
			s[index].id = sch_id;
		}
	}
	sort(s, s + index + 1, new_cmp);
	cout << s[0].id << " " << s[0].grades << endl;
	//system("pause");
	return 0;
}