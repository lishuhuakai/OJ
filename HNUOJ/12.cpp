#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

/**
 * ������Ŀ˵���ˣ�����һ���󽻼������⡣
 */
class DigitNum {
public:
	set<int> component; /* һ�����ֵ���ɲ��� */
public:
	bool isSubset(DigitNum &b) {
		/* �ж��Ƿ�Ϊ�Ӽ� */
		set<int>::iterator it = component.begin();
		while (it != component.end())
		{
			if (b.component.end() == b.component.find(*it))
				return false;
			++it;
		}
		return true;
	}
	DigitNum(int num) {
		/* ����Ҫ���������ֵ���ɲ����� */
		switch (num)
		{
		case 0: {
			component.insert(1); component.insert(2); 
			component.insert(3); component.insert(4);
			component.insert(5); component.insert(6); break;
		}
		case 1: {
			component.insert(3); component.insert(4);
			break;
		}
		case 2: {
			component.insert(2); component.insert(3);
			component.insert(5); component.insert(6);
			component.insert(7); break;
		}
		case 3: {
			component.insert(2); component.insert(3);
			component.insert(4); component.insert(5);
			component.insert(7); break;
		}
		case 4: {
			component.insert(1); component.insert(3);
			component.insert(4); component.insert(7);
			break;
		}
		case 5: {
			component.insert(1); component.insert(2);
			component.insert(4); component.insert(5);
			component.insert(7); break;
		}
		case 6: {
			component.insert(1); component.insert(2);
			component.insert(4); component.insert(5);
			component.insert(6); component.insert(7); break;
		}
		case 7: {
			component.insert(2); component.insert(3);
			component.insert(4); break;
		}
		case 8: {
			component.insert(1); component.insert(2);
			component.insert(3); component.insert(4);
			component.insert(5); component.insert(6);
			component.insert(7); break;
		}
		case 9: {
			component.insert(1); component.insert(2);
			component.insert(3); component.insert(4);
			component.insert(5); component.insert(7); break;
		}
		default:
			break;
		} 
	}
};

DigitNum* digit[10];

void init() {
	/* ���ڳ�ʼ���ĺ��� */
	for (int i = 0; i < 10; i++)
	{
		digit[i] = new DigitNum(i);
	}
}

bool Judge(int* array) {
	for (int i = 0; i < 10; i = i + 2) 
	{
		int idx1 = array[i];
		int idx2 = array[i + 1];
		DigitNum* a = digit[idx1];
		DigitNum* b = digit[idx2];
		if (!((a->isSubset(*b)) || (b->isSubset(*a)))) /* ����һ��������һ�����Ӽ� */
			return false;
	}
	return true;
}
int main()
{
	int input[10];
	init();
	while ((cin >> input[0]) && (input[0] != -1)) {
		for (int i = 1; i < 10; ++i)
			cin >> input[i]; /* ������Щֵ */
		if (Judge(input))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
	//system("pause");
	return 0;
}