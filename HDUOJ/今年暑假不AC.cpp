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
		//̰��
	/*
	������Begin[i]��End[i]��ʾ�¼�i�Ŀ�ʼʱ�̺ͽ���ʱ�̡�
	��ԭ���Ҫ�������һ���������a1<a2<��<an�����㣺
	Begin[a1]<End[a1]<=��<= Begin[an]<End[an]
	����֤��������ڿ��ܵ��¼�a1<a2<��<an��ѡȡ��ʱ���ϲ��ص�������У�
	��ôһ������һ������a1���������磩������С�
	��֤�����ԣ�
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

