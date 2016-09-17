#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str, short_str;
	while (cin >> str && str != "#")
	{
		cin >> short_str;
		string::size_type index = 0;
		int count = 0;
		while (1)
		{
			
			index = str.find(short_str, index);
			if (index == string::npos)
				break;
			else
				++count;
			index += short_str.length();
		}
		cout << count << endl;
	}
	return 0;
}