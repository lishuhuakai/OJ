#include <iostream>
#include <cstring>
using namespace std;
/*
 * 事实上，我想要关注的是，如何使得这个玩意不至于那么复杂
 * 简单一点，直接模拟算了,虽然这道题目正确，但是有没有更加好的办法呢？
*/
static int canvas[101][101]; /*为了简单起见，画布我直接从1开始了*/
void paint(int ldx, int ldy, int rux, int ruy)
{
	int xmin = ldx > rux ? rux : ldx;
	int xmax = ldx > rux ? ldx : rux; 
	int ymin = ldy > ruy ? ruy : ldy;
	int ymax = ldy > ruy ? ldy : ruy;
	for (int i = xmin; i < xmax; ++i)
	{
		for (int j = ymin; j < ymax; ++j)
		{
			canvas[i][j] = 1;
		}
	}
}

int main()
{
	int lines;
	cin >> lines;
	int ldx, ldy, rux, ruy; /*左下角x，y坐标，右上角x，y坐标*/
	for (int i = 0; i < lines; ++i)
	{
		cin >> ldx >> ldy >> rux >> ruy;
		paint(ldx, ldy, rux, ruy);
	}
	int counter = 0;
	for (int i = 1; i <= 100; ++i)
		for (int j = 1; j <= 100; ++j)
			if (canvas[i][j] != 0)
				counter++;
	cout << counter << endl;
	//system("pause");
	return 0;
}