#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct Money {
	int galleon;
	int sickle;
	int knut;
};

void calc(Money &p, Money &a, Money &rest)
{
	int p_numOfKnut = p.galleon * 17 * 29 + p.sickle * 29 + p.knut;
	int a_numOfKnut = a.galleon * 17 * 29 + a.sickle * 29 + a.knut;
	int rest_numOfKnut = a_numOfKnut - p_numOfKnut;
	bool flag = false; 
	if (rest_numOfKnut < 0)
	{
		flag = true;
		rest_numOfKnut = -rest_numOfKnut;
	}
	rest.galleon = rest_numOfKnut / 29 / 17;
	rest_numOfKnut = rest_numOfKnut - rest.galleon * 17 * 29;
	rest.sickle = rest_numOfKnut / 29;
	rest_numOfKnut = rest_numOfKnut - rest.sickle * 29;
	rest.knut = rest_numOfKnut;
	if (flag) rest.galleon = -rest.galleon;
}
int main()
{
	Money p, a, rest;
	scanf("%d.%d.%d", &(p.galleon), &(p.sickle), &(p.knut));
	scanf("%d.%d.%d", &(a.galleon), &(a.sickle), &(a.knut));
	calc(p, a, rest);
	cout << rest.galleon << "." << rest.sickle << "." << rest.knut << endl;
	//system("pause");
	return 0;
}