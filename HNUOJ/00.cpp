#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * ��̬�滮�����⣬���ںܼ򵥵�һ����Ŀ
 */

int main()
{
	int height_of_tower;
	vector<int> tower;

	int num_of_num = (1 + 100) * 100 / 2;
	tower.reserve(num_of_num + 1); //���ȷ�����㹻���ڴ�
	int temp;

	
	cin >> height_of_tower;
	num_of_num = (1 + height_of_tower) * height_of_tower / 2;
	tower.push_back(0); //tower[0] = 0,��ʹ��
	for (int i = 1; i <= num_of_num; ++i)
	{
		cin >> temp;
		tower.push_back(temp);
	}
	vector<int> value(tower.begin(), tower.end());
	vector<int> index(tower.size());
	/** 
	 * ��ʼdp,�ӵ�����һ�п�ʼ������������������Ի�õ����ļ�ֵ��
	 */
	for (int j = num_of_num - height_of_tower, n = height_of_tower, i = 0; j > 0; --j)
	{
		int lidx = j + n - 1;
		int ridx = j + n;
		int max;
		if (value[lidx] > value[ridx]) {
			index[j] = lidx;
			max = value[lidx];
		}
		else {
			index[j] = ridx;
			max = value[ridx];
		}
		value[j] = max + value[j]; //��������״̬ת�Ʒ���
		if (++i == n - 1)
		{
			--n;
			i = 0;
		}
	}
	cout << value[1] << endl;
	int trace = 1;
	cout << tower[1];
	for (int i = 0; i < height_of_tower - 1; ++i) {
		trace = index[trace];
		cout << " " << tower[trace];
	}
	cout << endl;
	tower.clear();
	//system("pause");
	return 0;
}