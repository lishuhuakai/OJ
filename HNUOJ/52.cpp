#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
struct RECORD {
	int num_item;
	float price_a;
	float price_b;
	float price_c;
	bool flag;
};
static RECORD rcd[40];

/*这道问题感觉是背包问题，真的！*/
/**
 * 有两个限制条件，第一个是单项物品的总价格不能超过600，另外一个是报销的总价值不能超过1000
 * 非常类似与背包问题，总之，一张发票只有两个状态，要么被报销，要么不被报销，所以我们可以将问题不断缩小
 * 好吧！ 我来做一做！
 */

float sumOfPrice(RECORD &rcd) /*计算发票的总价值*/
{
	return rcd.price_a + rcd.price_b + rcd.price_c;
}

float findMax(RECORD* rcd, float max, int size, float sum)
{ /*max是给定的最大的报销额度*/
	if (size == 0)
		return 0; /*你一张发票都不能报销，自然是0元*/
	if (size == 1 && sumOfPrice(rcd[0]) <= max)
		return sumOfPrice(rcd[0]);
	for (int i = 0; i < size; ++i)
	{
		/*现在开始做选择*/
		if (!rcd[i].flag) 
		{ /*这张发票可以选择报销*/
			// 面临这两种选择，第一种是选这张发票，另外一种是不选
			float value = sumOfPrice(rcd[i]); /* 计算出发票的价值 */
			float selec_value = value + sum; /* 选择了这张发票后的报销额度 */
			if (selec_value <= max) /*只有选了之后总价值不超过max才可以选择*/
			{
				float not_selec_value = findMax(&rcd[i + 1], max, size - i - 1, sum); /*不选第i张发票后得到的最大的价值*/
				if (selec_value > not_selec_value)
					/*废话，肯定不能选，是吧！*/
					sum = selec_value;
			}
		}
		/*否则的话，这张发票肯定不能选*/
	}
	return sum;
}
int main()
{
	float num_q;
	int num_n;
	while (true)
	{
		cin >> num_q >> num_n;
		memset(rcd, 0, sizeof(rcd));
		if (num_n == 0)
			break;
		for (int i = 0; i < num_n; ++i)
		{
			char catagory;
			float price;
			cin >> rcd[i].num_item;
			for (int j = 0; j < rcd[i].num_item; ++j)
			{
				scanf(" %c:%f", &catagory, &price);
				if (price > 600)
				{
					rcd[i].flag = true; /*这张发票不能报销*/
				}

				switch (catagory)
				{
				case 'A': rcd[i].price_a += price;
					break;
				case 'B': rcd[i].price_b += price;
					break;
				case 'C': rcd[i].price_c += price;
					break;
				default:
					rcd[i].flag = true; /*包含有其他类别的物品的发票不能报销*/
					break;
				}
			}
		}
		/*然后要开始计算最大的*/
		printf("%.2f\n", findMax(rcd, num_q, num_n, 0));
	}
	system("pause");
	return 0;
}