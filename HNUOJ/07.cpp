/**
 * ��ĳ��x�ֱ�d1��d2������dn���õ�����Ϊr1��r2������rn����ɱ�ʾΪ��ʽ��x = R1*r1 + R2*r2 + �� + Rn*rn + RD
 * ����R1��d2��d3������dn�Ĺ����������ұ�d1��������Ϊ1��...........
 * Rn��d1��d2������dn - 1�Ĺ����������ұ�dn��������Ϊ1��
 * D��d1��d2������dn����С��������
 * R��������������d1��d2������dn���뻥�ʡ�
 */

#include<iostream>
using namespace std;
int p, e, i, d, sum = 1;

int Val(int a, int b, int c)
{
	int num;
	for (num = b*c;; num += b*c)
		if (num%a == 1) break; // ���һ��numֵ������b��c�Ĺ����������Ǳ�a��������Ϊ1
	return num;
}
int main()
{
	while (cin >> p >> e >> i >> d)
	{
		if (p == -1 && e == -1 && i == -1 && d == -1) break;
		/**
		 * �����p,e,i�ֱ������������к������߷���ֵ�ʱ�䣨ʱ��ӵ���ĵ�һ�쿪ʼ���㣩
		 * d�Ǹ�����ʱ�䣬��ΪҪ�������ʱ��С��21252������ mod 21252
		 * ��ʼ����һ�죬
		 */
		int res = (p * Val(23, 28, 33) + e * Val(28, 23, 33) + i * Val(33, 23, 28)) % 21252 - d;//����Ļ�����ֱ������������Խ�ʡʱ�䡣
		if (res <= 0) res += 21252;
		cout << "Case " << sum++ << ": the next triple peak occurs in " << res << " days." << endl;
	}
	return 0;
}
