/**
 * 若某数x分别被d1、d2、…、dn除得的余数为r1、r2、…、rn，则可表示为下式：x = R1*r1 + R2*r2 + … + Rn*rn + RD
 * 其中R1是d2、d3、…、dn的公倍数，而且被d1除，余数为1；...........
 * Rn是d1、d2、…、dn - 1的公倍数，而且被dn除，余数为1；
 * D是d1、d2、…、dn的最小公倍数；
 * R是任意整数，且d1、d2、…、dn必须互质。
 */

#include<iostream>
using namespace std;
int p, e, i, d, sum = 1;

int Val(int a, int b, int c)
{
	int num;
	for (num = b*c;; num += b*c)
		if (num%a == 1) break; // 求出一个num值，它是b和c的公倍数，但是被a除，余数为1
	return num;
}
int main()
{
	while (cin >> p >> e >> i >> d)
	{
		if (p == -1 && e == -1 && i == -1 && d == -1) break;
		/**
		 * 输入的p,e,i分别代表体力、情感和智力高峰出现的时间（时间从当年的第一天开始计算）
		 * d是给定的时间，因为要求所求的时间小于21252，所以 mod 21252
		 * 开始的这一天，
		 */
		int res = (p * Val(23, 28, 33) + e * Val(28, 23, 33) + i * Val(33, 23, 28)) % 21252 - d;//这里的话可以直接算出来，可以节省时间。
		if (res <= 0) res += 21252;
		cout << "Case " << sum++ << ": the next triple peak occurs in " << res << " days." << endl;
	}
	return 0;
}
