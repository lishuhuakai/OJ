#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
/*
bool dec_judge(int num) //十进制的判断
{
	int tmp = 0;
	int sum = 0;
	for (int i = 0; i < 4; ++i)
	{
		tmp = num % 10;
		sum += tmp;
		num = num / 10;
	}
	if (sum == 22)
		return true;
	else
		return false;
}
bool hex_judge(int num)
{

	int tmp = 0;
	int sum = 0;
	for (int i = 0; num != 0; ++i)
	{
		tmp = num % 16;
		sum += tmp;
		num = num / 16;
	}
	if (sum == 22)
		return true;
	else
		return false;
}

bool twe_judge(int num) //十二进制的判断
{
	int tmp = 0;
	int sum = 0;
	for (int i = 0; num != 0; ++i)
	{
		tmp = num % 12;
		sum += tmp;
		num = num / 12;
	}
	if (sum == 22)
		return true;
	else
		return false;
}
*/
int sky_judge(int num, int hex) //代码复用，上面的三个函数可以合并成一个函数
{
	int sum = 0;
	while(num)
	{
		sum += num % hex;
		num = num / hex;
	}
	return sum;
}

bool is_sky_num(int num) //用来判断一个数是否为sky数
{
	int sum = sky_judge(num, 10);
	if (sum != sky_judge(num, 16))
		return false;
	if (sum != sky_judge(num, 12))
		return false;
	return true;
}
int main()
{
	int num;
	while (cin >> num && num)
	{
		if (is_sky_num(num))
			cout << num << " is a Sky Number." << endl;
		else
			cout << num << " is not a Sky Number." << endl;
	}
	return 0;
}
