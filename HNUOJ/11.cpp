#include <iostream>
#include <algorithm>
using namespace std;

/* 我现在看到这类问题就想吐！ */
typedef struct Polynomial
{
	int degree;
	int factor;
}poly;

poly addend[2][200];
poly res[200];

bool cmp(const poly& l, const poly &r)
{
	/* 按照degree从高到低排序 */
	return l.degree > r.degree;
}

int main()
{
	int len[2];
	for (int i = 0; i < 2; ++i)
	{
		int index = 0;
		while (cin >> addend[i][index].degree >> addend[i][index].factor)
		{
			if (addend[i][index].degree == 0 && addend[i][index].factor == 0)
				break;
			index++;
		}
		sort(addend[i], addend[i] + index, cmp);
		len[i] = index;
	}
	/*然后开始加法了！*/
	int index0 = 0;
	int index1 = 0;
	int index = 0;
	
	for (;index < 200 ; ++index)
	{
		if (addend[0][index0].degree > addend[1][index1].degree)
		{
			res[index].degree = addend[0][index0].degree;
			res[index].factor = addend[0][index0].factor;
			index0++;
		}
		else if (addend[0][index0].degree < addend[1][index1].degree)
		{
			res[index].degree = addend[1][index1].degree;
			res[index].factor = addend[1][index1].factor;
			index1++;
		}
		else
		{
			res[index].degree = addend[1][index1].degree;
			res[index].factor = addend[0][index0].factor + addend[1][index1].factor;
			index0++;
			index1++;
		}
		
	}
	for (int i = 0; ; i++)
	{
		if (res[i].factor == 0 && res[i].degree == 0)
			break;
		else
			cout << res[i].degree << " " << res[i].factor << endl;
	}
	//system("pause");
	return 0;
}