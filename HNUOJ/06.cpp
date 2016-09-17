#include <iostream>
#include <iomanip>
using namespace std;

char weekday[7][10] = { "Saturday", "Sunday", "Monday", 
"Tuesday", "Wednesday", "Thursday", "Friday" };

int year[2] = { 365, 366 };

int month[2][12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
					 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //�ֱ���ƽ����·�������������·����������ġ�ϸ�ģ�ע���year˳���Ӧ

int leap(int i) { //�ж��������ע���year��Ӧ
	if ((i % 4 != 0) || (i % 100 == 0 && i % 400 != 0))  return 0;//0��ƽ��
	else return 1;//1������
}

int main() {
	int days = 0, dayofweek;
	int i = 0, j = 0;
	while (days != -1) {
		cin >> days;
		if (days == -1) break;
		dayofweek = days % 7;// ȡģ�õ����ڼ�
		for (i = 2000; days >= year[leap(i)]; i++) {
			days -= year[leap(i)];
		}
		for (j = 0; days >= month[leap(i)][j]; j++)//������ͬ������ÿ���µ�������ֱ��С�ڵ�������
		{
			days -= month[leap(i)][j];
		}
		printf("%d-%02d-%02d %s", i, j + 1, days + 1, week[dayofweek]);
	}
	return 0;
}


