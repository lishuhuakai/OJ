#include <iostream>
#include <cstdio>
using namespace std;

double getPoint(int x)
{
	if (90 <= x && x <= 100)
		return 4.0;
	else if (85 <= x && x <= 89)
		return 3.7;
	else if (82 <= x && x <= 84)
		return 3.3;
	else if (78 <= x && x <= 81)
		return 3.0;
	else if (75 <= x && x <= 77)
		return 2.7;
	else if (72 <= x && x <= 74)
		return 2.3;
	else if (68 <= x && x <= 71)
		return 2.0;
	else if (64 <= x && x <= 67)
		return 1.5;
	else if (60 <= x && x <= 63)
		return 1.0;
	else
		return 0;
}

int credits[1024];
int grades[1024];

int main()
{
	int numOfCourse;
	while (cin >> numOfCourse)
	{
		int sumOfCredits = 0;
		for (int i = 0; i < numOfCourse; ++i)
		{
			cin >> credits[i]; /*输入学分*/
			sumOfCredits += credits[i];
		}
		for (int i = 0; i < numOfCourse; ++i)
		{
			cin >> grades[i]; /*输入成绩*/
		}
		double sumOfGP = 0;
		for (int i = 0; i < numOfCourse; ++i)
		{
			sumOfGP = sumOfGP + getPoint(grades[i]) * credits[i];
		}
		printf("%.2lf\n", sumOfGP / sumOfCredits);
	}
	
	//system("pause");
	return 0;
}