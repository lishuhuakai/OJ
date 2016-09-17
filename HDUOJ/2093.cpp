#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<iomanip>
using namespace std;

#define SIZE 1000
typedef struct _score_info 
{
	string name;
	int ac_num; //接受了的题目的数目
	int time_score; //时间分
}S_INFO;

S_INFO info[SIZE];
string score[12];
int num_of_question;//问题的数目
int num;//每次罚的分数

class special_sort
{
public:
	bool operator () (const S_INFO &l, const S_INFO &r)
	{
		return (l.ac_num > r.ac_num || l.time_score < r.time_score || l.name < r.name);
	}
};

int main_01()
{	
	cin >> num_of_question >> num;
	int index = 0;
	while(cin >> info[index].name)
	{
		
		int sum = 0; //得到的时间总分
		int count = 0; //解决的题目数
		info[index].ac_num = info[index].time_score = 0;
		for (int j = 0; j < num_of_question; ++j)
		{
			cin >> score[j];
			string::size_type str_index = score[j].find('('); //找到下标
			if (str_index != string::npos) //找到了
			{
				count++;
				string substr = score[j].substr(0, str_index);
				sum += atoi(substr.c_str());
				substr = score[j].substr(str_index + 1, score[j].length() - (str_index + 2));
				sum += atoi(substr.c_str()) * num;
			}
			else //没找到
			{
				int temp = atoi(score[j].c_str());
				if (temp > 0)
				{
					sum += temp;
					count++;
				}

			}
			
		}
		info[index].ac_num = count;
		info[index].time_score = sum;
		index++;
	}

	sort(info, info + index, special_sort());
	for (int j = 0; j < index; ++j)
	{
		cout.flags(ios::left);
		cout << setw(10) <<info[j].name;
		cout << " " << setiosflags(ios::right) << setw(2) << info[j].ac_num;
		cout << " " << setiosflags(ios::right) << setw(4) << info[j].time_score;
		cout << endl;
	}
	system("pause");
	return 0;
}

int main()
{
	vector<string> str_vector;
	str_vector.reserve(1024);

	copy(istream_iterator<string>(cin), istream_iterator<string>(),
		back_inserter(str_vector)); //尾部插入
	
	copy(str_vector.begin(), str_vector.end(),
		ostream_iterator<string>(cout, " "));

	cout << endl;
	system("pause");
	return 0;
}