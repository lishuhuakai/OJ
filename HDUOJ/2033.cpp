#include <iostream>
using namespace std;

typedef struct _time
{
	int h;
	int m;
	int s;
}Time;

Time operator+(Time &l, Time &r)
{
	Time t;
	t.s = l.s + r.s;
	t.m = l.m + r.m + t.s / 60;
	t.s %= 60;
	t.h = l.h + r.h + t.m / 60;
	t.m %= 60;
	return t;
}
ostream& operator<< (ostream &os, Time &v)
{
	os << v.h << " " << v.m << " " << v.s;
	return os;
}
istream& operator>>(istream &is, Time &v)
{
	is >> v.h >> v.m >> v.s;
	return is;
}

int main()
{
	int n;
	cin >> n;
	Time l, r;
	while(n--)
	{
		cin >> l >> r;
		Time s = l + r;
		cout << s << endl;
	}
	return 0;
}
