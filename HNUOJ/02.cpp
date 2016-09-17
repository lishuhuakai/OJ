#include <iostream>
#include <algorithm>
using namespace std;
static int buf[1024];
struct RANK {
	int num;  /*������������*/
	int counter; /*���ֵĴ���*/
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
	sort(buf, buf + num); // ��������
	int rindex = 0;
	for (int i = 0; i < num; )
	{
		res[rindex].num = buf[i];
		while (res[rindex].num == buf[i])
		{
			++i;
			res[rindex].counter += 1;
			if (i >= num) /*��ֹԽ��*/
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