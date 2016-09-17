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

/*�������о��Ǳ������⣬��ģ�*/
/**
 * ������������������һ���ǵ�����Ʒ���ܼ۸��ܳ���600������һ���Ǳ������ܼ�ֵ���ܳ���1000
 * �ǳ������뱳�����⣬��֮��һ�ŷ�Ʊֻ������״̬��Ҫô��������Ҫô�����������������ǿ��Խ����ⲻ����С
 * �ðɣ� ������һ����
 */

float sumOfPrice(RECORD &rcd) /*���㷢Ʊ���ܼ�ֵ*/
{
	return rcd.price_a + rcd.price_b + rcd.price_c;
}

float findMax(RECORD* rcd, float max, int size, float sum)
{ /*max�Ǹ��������ı������*/
	if (size == 0)
		return 0; /*��һ�ŷ�Ʊ�����ܱ�������Ȼ��0Ԫ*/
	if (size == 1 && sumOfPrice(rcd[0]) <= max)
		return sumOfPrice(rcd[0]);
	for (int i = 0; i < size; ++i)
	{
		/*���ڿ�ʼ��ѡ��*/
		if (!rcd[i].flag) 
		{ /*���ŷ�Ʊ����ѡ����*/
			// ����������ѡ�񣬵�һ����ѡ���ŷ�Ʊ������һ���ǲ�ѡ
			float value = sumOfPrice(rcd[i]); /* �������Ʊ�ļ�ֵ */
			float selec_value = value + sum; /* ѡ�������ŷ�Ʊ��ı������ */
			if (selec_value <= max) /*ֻ��ѡ��֮���ܼ�ֵ������max�ſ���ѡ��*/
			{
				float not_selec_value = findMax(&rcd[i + 1], max, size - i - 1, sum); /*��ѡ��i�ŷ�Ʊ��õ������ļ�ֵ*/
				if (selec_value > not_selec_value)
					/*�ϻ����϶�����ѡ���ǰɣ�*/
					sum = selec_value;
			}
		}
		/*����Ļ������ŷ�Ʊ�϶�����ѡ*/
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
					rcd[i].flag = true; /*���ŷ�Ʊ���ܱ���*/
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
					rcd[i].flag = true; /*����������������Ʒ�ķ�Ʊ���ܱ���*/
					break;
				}
			}
		}
		/*Ȼ��Ҫ��ʼ��������*/
		printf("%.2f\n", findMax(rcd, num_q, num_n, 0));
	}
	system("pause");
	return 0;
}