//现在弄到一个判断二分匹配的算法，仔细研究研究，很爽的！
#include<iostream>
using namespace std;
const int Max=500;

int g[Max][Max];
int linker[Max];
bool used[Max];

bool dfs(int u)
{
	int v;
	for(v=1;v<=g[0][1];v++)
	{
		if(g[u][v] && !used[v])
		{
			used[v]=true;
			if(linker[v]==-1 || dfs(linker[v]))
			{
				linker[v]=u;
				return true;
			}
		}
	}
	return false;
}

int hungary()
{
	int res=0;
	int u;
	memset(linker,-1,sizeof(linker));

	for(u=1;u<=g[0][0];u++)
	{
		memset(used,0,sizeof(used));
		if(dfs(u)) res++;
	}
	return res;
}

int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		int num,m;
		memset(g,0,sizeof(g));
		cin>>g[0][0]>>g[0][1];
		for(int i=1;i<=g[0][0];i++)
		{
			cin>>num;
			for(int j=0;j<num;j++)
			{
				cin>>m;
				g[i][m]=1;
			}
		}
		if(hungary()!=g[0][0])
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;

	}
	return 0;
}
