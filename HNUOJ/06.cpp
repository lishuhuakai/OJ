#include <iostream>
#include <iomanip>
using namespace std;

char weekday[7][10] = { "Saturday", "Sunday", "Monday", 
"Tuesday", "Wednesday", "Thursday", "Friday" };

int year[2] = { 365, 366 };

int month[2][12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
					 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //分别是平年的月份天数和闰年的月份天数。耐心、细心！注意和year顺序对应

int leap(int i) { //判断闰年与否，注意和year对应
	if ((i % 4 != 0) || (i % 100 == 0 && i % 400 != 0))  return 0;//0是平年
	else return 1;//1是闰年
}

int main() {
	int days = 0, dayofweek;
	int i = 0, j = 0;
	while (days != -1) {
		cin >> days;
		if (days == -1) break;
		dayofweek = days % 7;// 取模得到星期几
		for (i = 2000; days >= year[leap(i)]; i++) {
			days -= year[leap(i)];
		}
		for (j = 0; days >= month[leap(i)][j]; j++)//与上面同理，减掉每个月的天数，直到小于当月天数
		{
			days -= month[leap(i)][j];
		}
		printf("%d-%02d-%02d %s", i, j + 1, days + 1, week[dayofweek]);
	}
	return 0;
}


