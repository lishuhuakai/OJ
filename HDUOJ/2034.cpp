#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

void output(set<int> &v)
{
	set<int>::iterator it = v.begin();
	for (; it != v.end(); ++it)
	{
		cout << *it << " ";
	}
}

int main()
{
	set<int> n_elem, m_elem, o_elem;
	int n, m;
	while(cin >> n >> m && !(n == 0 && m == 0))
	{
		copy_n(istream_iterator<int>(cin), n, inserter(n_elem, n_elem.end()));
		//copy_n(istream_iterator<int>(cin), m, inserter(m_elem, m_elem.end()));
		int val;
		for (int i = 0; i < n; ++i)
		{
			cin >> val;
			n_elem.insert(val);
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> val;
			m_elem.insert(val);
		}
	
		set_difference(n_elem.begin(), n_elem.end(),
			m_elem.begin(), m_elem.end(),
			inserter(o_elem, o_elem.end()));
		if (o_elem.size() == 0)
			cout << "NULL";
		else
		{
			//output(o_elem);
			copy(o_elem.begin(), o_elem.end(), ostream_iterator<int>(cout, " "));
		}
		cout << endl;
		n_elem.clear();
		m_elem.clear();
		o_elem.clear();
	}
	return 0;
}