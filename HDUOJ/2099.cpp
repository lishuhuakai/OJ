#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
using namespace std;

/* *思路：
*  既然是只是不知道后两位，那么就将a*100，然后除以b取余，我们知道(a*100-c)%b=0
*  ==>c = (a*100-c+b)%b,此时c为最小的一个解 
*  关键是如何得到其他的解，很简单，c + n * b即为解，需要注意的是：
*  0 <= c + n * b < 100
*  KO!
* */
int main()
{
	int a, b;
	while (1)
	{
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
			break;
		int c = (a * 100) % b;
		c = (b - c) % b;
		printf("%02d", c);
		int d = 0;
		for (int i = 1; ; ++i)
		{
			d = c + i * b;
			
			if (d >= 100)
				break;
			printf(" %02d", d);
		}
		printf("\n");
	}
	//system("pause");
	return 0;
}
