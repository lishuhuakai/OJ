//���������Ȼ�Ƚ�С�����ǰ����ĸ��ּ��ܻ��Ǻܶ�ģ�
/*
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int n,sumtime,num;
	double d;
	char h,m1,m2,s1,s2;
	scanf("%d",&n);
    scanf("%lf",&d);
	while(scanf("%d",&num)!=EOF)//��Ŀ��˼�Ƕ���ÿ������������
	{
		printf("%3d ",num);
		bool flag=true;
		sumtime=0;
		for(int i=0;i<n;i++)
		{
			getchar();
			scanf("%c:%c%c:%c%c",&h,&m1,&m2,&s1,&s2);
			if(h=='-') flag=false;
			if(flag==false) continue;//�������������"-:--:--",��ô�������Ͳ��ü����ˣ�
			sumtime=sumtime+(h-'0')*3600+((m1-'0')*10+(m2-'0'))*60+(s1-'0')*10+s2-'0';
		}
		//cout<<sumtime<<endl;//���������ʱ������ȷ�ģ�
		
		if(flag)
		{
			int t2=sumtime/d+0.5;//�����������ƽ��ÿ��һǧ������Ҫ��ʱ�䣨s��,�����������ݵ�Ե����Ҫ�������룡
			//cout<<"t2="<<t2<<endl;
			if(t2-t2/60*60<10)
			printf("%d:0%d min/km\n",t2/60,t2-t2/60*60);
			else
            printf("%d:%d min/km\n",t2/60,t2-t2/60*60);
		}
		else
			printf("-\n");

	}
	return 0;
}
*/
//����Ҫ����һ����������һЩ���⣡
/*
#include<stdio.h>

int main()
{
	int num;
	while(scanf("%d",&num)!=EOF)//���Խ������������֮ǰ������ٸ��ո񶼲��ᱻ����num��һ��������num��ֵ����Щֵ�ᱻ��ջ��Ȼ����ִ�У����֮ǰ�γ����ʱ�����������һ���ģ�
	{
		printf("%d\n",num);
	}
	return 0;
}
*/
//����һ�����AC��ģ��Ǿ�������ʹ��Ƿֿ��ģ�AC��ֻ���𰸣�
#include<iostream>
using namespace std;

int main()
{
    int num;
    while(cin>>num)
    {
      cout<<num<<endl;
    }
    return 0;
}
