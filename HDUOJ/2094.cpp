#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
using namespace std;

#define MAX_NUM 2000
#define MAX_NAME_LEN 32


int main()
{
	//˼·��ֻ��Ҫ�ж�˭���ǹھ�����
	int mark[MAX_NUM]; //�������
	int num_of_demo; //���Ե�����
    
	while (scanf("%d", &num_of_demo) && num_of_demo != 0)
	{
		string first_name, second_name;
		memset(mark, 0, sizeof(mark));
		map<string, int> name_map;
		int index = 0; //ָʾ��
		int count = 0;
		for (int i = 0; i < num_of_demo; ++i)
		{
			//scanf("%s %s", &first_name, &second_name);
			cin >> first_name >> second_name;
			map<string, int>::iterator it1, it2;
			it1 = name_map.find(first_name);
			it2 = name_map.find(second_name);

			if (it1 == name_map.end())
			{//��������ڣ�����
				name_map.insert(make_pair(first_name, index++));
			}
			if (it2 == name_map.end())
			{
				name_map.insert(make_pair(second_name, index++));
				mark[index - 1] = -1; //��λ�����ܳ�Ϊ�ھ�
			}
			else
			{
				mark[it2->second] = -1;
			}
		}

		for (int i = 0; i < index; ++i)
		{
			if (mark[i] == 0)
			{
				count++;
			}
		}
		if (count == 1)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}

	return 0;
}