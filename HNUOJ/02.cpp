#include <iostream>
#include <algorithm>
using namespace std;
static int buf[1024];
struct RANK {
	int num;  /*具体的这个数字*/
	int counter; /*出现的次数*/
};
static RANK res[1024];
bool cmp(const RANK &l, const RANK &r)
{
	if (l.counter != r.counter)
		return l.counter > r.counter;
	else
		return l.num < r.num;
}

int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		cin >> buf[i];
	}
	sort(buf, buf + num); // 首先排序
	int rindex = 0;
	for (int i = 0; i < num; )
	{
		res[rindex].num = buf[i];
		while (res[rindex].num == buf[i])
		{
			++i;
			res[rindex].counter += 1;
			if (i >= num) /*防止越界*/
				break;
		}
		rindex++;
	}
	sort(res, res + rindex, cmp);
	for (int i = 0; i < rindex; ++i)
	{
		cout << res[i].num << " " << res[i].counter << endl;
	}
	//system("pause");
	return 0;
}