#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct StuInfo
{
	char name[12]; // the name of student
	char id[12];
	int score;
};

struct cmp
{
	bool operator () (const StuInfo& x, const StuInfo& y)
	{
		return x.score > y.score;
	}
};

static StuInfo dataSet[1024];

int main()
{
	int numOfStu;
	cin >> numOfStu;
	for (int i = 0; i < numOfStu; ++i)
	{
		cin >> dataSet[i].name >> dataSet[i].id >> dataSet[i].score;
	}
	sort(dataSet, dataSet + numOfStu, cmp());
	cout << dataSet[0].name << " "<< dataSet[0].id << endl;
	int last = numOfStu - 1;
	cout << dataSet[last].name << " " << dataSet[last].id << endl;
	system("pause");
	return 0;
}