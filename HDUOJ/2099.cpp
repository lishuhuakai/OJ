#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
using namespace std;

/* *˼·��
*  ��Ȼ��ֻ�ǲ�֪������λ����ô�ͽ�a*100��Ȼ�����bȡ�࣬����֪��(a*100-c)%b=0
*  ==>c = (a*100-c+b)%b,��ʱcΪ��С��һ���� 
*  �ؼ�����εõ������Ľ⣬�ܼ򵥣�c + n * b��Ϊ�⣬��Ҫע����ǣ�
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
