#include <iostream>
using namespace std;

double eps = 0.00001;

double fn(double x)
{
	return x * x * x - x - 1;
}
double _abs(double x)
{
	return x > 0 ? x : -x;
}
/*��ţ�ٶ��ַ�������ɣ�*/
double newton_dichotomy(double l, double r)
{ /*l����߽磬r���ұ߽�*/
	double res = fn(l);
	double tmp = l;
	while (_abs(res) > eps) 
	{
		double mid = (l + r) / 2;
		res = fn(mid);
		if (fn(l) * res < 0)
			r = mid;
		else if (res * fn(r) < 0)
			l = mid;
		tmp = mid;
	}
	return tmp;
}

int main()
{
	double l, r;
	while (cin >> l >> r)
	{
		if (fn(l) * fn(r) > 0)
			printf("No zero point in area(%.5lf,%.5lf)\n", l, r);
		else
			printf("The Zero Point is %.5lf in area(%.5lf,%.5lf)", newton_dichotomy(l, r), l, r);
	}
	//system("pause");
	return 0;
}