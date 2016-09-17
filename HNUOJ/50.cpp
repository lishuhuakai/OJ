#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;

typedef struct NODE {
	char id; /*用来标识自己*/
	NODE* parent[2]; /*最多只有两个父母，是吧!*/
}node;

node* new_node(char id)
{
	node* p = (node*)malloc(sizeof(node));
	p->id = id;
	p->parent[0] = p->parent[1] = NULL;
	return p;
}

map<char, node*> mp;

node* find(char id)
{ /*用于在mp中寻找对应的值*/
	map<char, node*>::iterator it;
	it = mp.find(id);
	if (it != mp.end())
		return mp[id];
	else
		return NULL;
}

int bfs(node* nd, char target)
{ /*使用bfs来遍历吧！我知道这玩意离不开递归的！*/
	if (nd->id == target)
		return 0;
	if (nd->parent[0] == NULL && nd->parent[1] == NULL)
		return -999;
	if (nd->parent[0] !=NULL  && nd->parent[1] == NULL) /*应该只有这一种情况*/
		return 1 + bfs(nd->parent[0], target);
	int res1 = bfs(nd->parent[0], target) + 1;
	if (res1 > 0)
		return res1;
	int res2 = bfs(nd->parent[1], target) + 1;
	if (res2 > 0)
		return res2;
	return -999;
}

void output2(int lever)
{
	if (lever < 1)
		return;
	if (lever == 1)
		cout << "parent" << endl;
	else if (lever == 2)
	{
		cout << "grand";
		output2(1);
	}
	else
	{
		cout << "great-";
		output2(lever - 1);
	}
		
}

void output1(int lever)
{
	if (lever < 1)
		return;
	if (lever == 1)
		cout << "child" << endl;
	else if (lever == 2)
	{
		cout << "grand";
		output1(1);
	}
	else
	{
		cout << "great-";
		output1(lever - 1);
	}

}

/*对于这种玩意，我们需要构造一棵树*/
int main()
{
	int numOfTest, numOfRelations;
	char buf[10];
	while (cin >> numOfRelations >> numOfTest)
	{
		if (numOfRelations == 0 && numOfTest == 0)
			break;
		for (int i = 0; i < numOfRelations; ++i)
		{
			cin >> buf; // 得到对应的关系
			int len = strlen(buf);
			node* nd = find(buf[0]);
			if (nd == NULL)
			{
				nd = new_node(buf[0]);
				mp[buf[0]] = nd; /*我们需要将这些东西记录下来*/
			}

			for (int i = 1; i < len; ++i)
			{
				node* pn = find(buf[i]);
				if (pn == NULL)
				{
					pn = new_node(buf[i]); /*构建一个新的节点*/
					mp[buf[i]] = pn;
				}
				nd->parent[i - 1] = pn;
			}
		}
		/**
		* 通过上面的一些步骤，我们已经构造好了家族树了!
		* 接下来只需要遍历即可!
		*/
		for (int i = 0; i < numOfTest; ++i)
		{
			cin >> buf;
			node* nd = find(buf[0]); /*找到对应的节点，开始遍历了*/
			int res1 = bfs(nd, buf[1]);
			if (res1 > 0)
			{
				output1(res1);
			}
			else
			{
				nd = find(buf[1]);
				int res2 = bfs(nd, buf[0]);
				if (res2 > 0)
				{
					output2(res2);
				}
				else
					cout << "-" << endl;
			}
		}
	}
	//system("pause");
	return 0;
}