#include <iostream>
#include <vector>
//#include <iterator>
#include <algorithm>
using namespace std;
/*��̬�滮�����⣬���ںܼ򵥵�һ����Ŀ
 */

int main()
{
	int num_of_case, height_of_tower;
	cin >> num_of_case;
	vector<int> tower;
	
	int num_of_num = (1 + 100) * 100 / 2;
	tower.reserve(num_of_num + 1); //���ȷ�����㹻���ڴ�
	int temp;

	while (num_of_case-- > 0)
	{
		cin >> height_of_tower;
		num_of_num = (1 + height_of_tower) * height_of_tower / 2;
		tower.push_back(0); //tower[0] = 0,��ʹ��
		for (int i = 1; i <= num_of_num; ++i)
		{
			cin >> temp;
			//copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(tower));
			//cin >> back_inserter(tower); //�õ�����
			tower.push_back(temp);
		}
		vector<int> value(tower.begin(), tower.end());
		//��ʼdp
		for (int j = num_of_num - height_of_tower, n = height_of_tower, i = 0; j > 0; --j)
		{
			value[j] = max(value[j + n], value[j + n - 1]) + value[j]; //��������״̬ת�Ʒ���
			if (++i == n - 1)
			{
				--n;
				i = 0;
			}
		}
		cout << value[1] << endl;
		tower.clear();
	}
	system("pause");
	return 0;
}