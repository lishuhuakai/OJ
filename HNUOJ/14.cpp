#include <iostream>
#include <algorithm>
using namespace std;

struct RANK {
	int id; // the identifier of participate
	int grades; 
};
static RANK parti[100]; // 100 is enough

void init(int num)
{
	for (int i = 0; i < num; ++i)
	{
		parti[i].id = i;
	}
}
struct CMP {
	bool operator() (const RANK &a, const RANK &b)
	{
		return a.grades > b.grades;
	}
};

int main()
{
	int numOfP;
	cin >> numOfP;
	init(numOfP);
	for (int i = 0; i < numOfP; ++i)
	{
		parti[i].id = i;
		cin >> parti[i].grades;
	}
	sort(parti, parti + numOfP, CMP());
	int res[100];
	int rank = 1;
	res[parti[0].id] = rank;
	for (int i = 1; i < numOfP; ++i)
	{
		if (parti[i - 1].grades > parti[i].grades) ++rank;
		//res[i] = parti[i].id + 1;
		res[parti[i].id] = rank;
		
	}
	for (int i = 0; i < numOfP - 1; ++i)
	{
		cout << res[i] << " ";
	}
	cout << res[numOfP - 1] << endl;
	//system("pause");
	return 0;
}