#include<iostream>
#include<algorithm>
using namespace std;

struct Time
{
	int start;
	int end;
}time[200];

bool cmp(const Time &a,const Time &b)
{
	if(a.end!=b.end)
		return a.end<b.end;
	else
		return a.start<b.start;
}

int main()
{
	int n,i;
	while(cin>>n)
	{
      if(n==0) break;
		for(i=0;i<n;i++)
		cin>>time[i].start>>time[i].end;
		//cin>>temp;

		sort(time,time+n,cmp);

		//for(i=0;i<n;i++)
		//cout<<time[i].start<<" "<<time[i].end<<endl;
		//贪心
	/*
	不妨用Begin[i]和End[i]表示事件i的开始时刻和结束时刻。
	则原题的要求就是找一个最长的序列a1<a2<…<an，满足：
	Begin[a1]<End[a1]<=…<= Begin[an]<End[an]
	可以证明，如果在可能的事件a1<a2<…<an中选取在时间上不重叠的最长序列，
	那么一定存在一个包含a1（结束最早）的最长序列。
	（证明：略）
	*/

		int min=time[0].end;
		int s=1;
		for(i=1;i<n;i++)
		{
			//if(min>time[i].start) continue;
			if(min<=time[i].start)
			{
				min=time[i].end;
				s++;
			}
		}
		cout<<s<<endl;
	}
	system("pause");
	return 0;
}

