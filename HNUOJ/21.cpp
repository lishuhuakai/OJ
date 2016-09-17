#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int SIZE = 1024;
static char  dividend[SIZE]; /*被除数*/
static char quotient[SIZE]; /*商*/
/*
这个玩意需要我们手动来模拟除法
*/
int main()
{
	int divisor; /*除数*/
	cin >> dividend >> divisor;
	int divid_len = strlen(dividend); /*得到被除数的长度信息*/
	int quot_pos = 0; /*用于指示商的位置*/
	int remainder = 0; /*余数*/
	for (int i = 0; i < divid_len; ++i)
	{
		remainder *= 10; /*和手工模拟一样，进入下一位时，低位要变为高位*/
		int highest_part_dvdent = dividend[i] - '0';  /*被除数的最高位的值*/
		int high_part_dvdent = remainder + highest_part_dvdent; /*被除数的高位的值*/
		if (high_part_dvdent < divisor) /*现在我们要借位*/
		{
			quotient[quot_pos++] = '0';
			remainder = highest_part_dvdent;
		}
		else
		{
			/*现在可以相除了*/
			remainder = high_part_dvdent % divisor; /*得到余数*/
			quotient[quot_pos++] = (high_part_dvdent / divisor) + '0'; /*转换成为商*/
		}
	}
	quotient[quot_pos] = '\0';
	/*还需要做的一件事情，就是不要显示最前面的0*/
	char * res = quotient;
	while (*res == '0') res++;
	cout << res << " " << remainder << endl;
	system("pause");
	return 0;
}