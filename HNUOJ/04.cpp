#include <iostream>
#include <cstring>
using namespace std;
/*
 * ��ʵ�ϣ�����Ҫ��ע���ǣ����ʹ��������ⲻ������ô����
 * ��һ�㣬ֱ��ģ������,��Ȼ�����Ŀ��ȷ��������û�и��Ӻõİ취�أ�
*/
static int canvas[101][101]; /*Ϊ�˼������������ֱ�Ӵ�1��ʼ��*/
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
	int ldx, ldy, rux, ruy; /*���½�x��y���꣬���Ͻ�x��y����*/
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