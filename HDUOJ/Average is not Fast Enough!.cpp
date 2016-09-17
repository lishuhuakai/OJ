//这个程序虽然比较小，但是包含的各种技能还是很多的！
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
	while(scanf("%d",&num)!=EOF)//题目意思是对于每个队伍便输出答案
	{
		printf("%3d ",num);
		bool flag=true;
		sumtime=0;
		for(int i=0;i<n;i++)
		{
			getchar();
			scanf("%c:%c%c:%c%c",&h,&m1,&m2,&s1,&s2);
			if(h=='-') flag=false;
			if(flag==false) continue;//这里如果输入了"-:--:--",那么接下来就不用计算了！
			sumtime=sumtime+(h-'0')*3600+((m1-'0')*10+(m2-'0'))*60+(s1-'0')*10+s2-'0';
		}
		//cout<<sumtime<<endl;//这里计算总时间是正确的！
		
		if(flag)
		{
			int t2=sumtime/d+0.5;//这里算出来了平均每走一千米所需要的时间（s）,这里由于数据的缘故需要四舍五入！
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
//我想要测试一下所遇到的一些问题！
/*
#include<stdio.h>

int main()
{
	int num;
	while(scanf("%d",&num)!=EOF)//测试结果表明：无论之前输入多少个空格都不会被记入num，一次输入多个num的值，这些值会被入栈！然后再执行！这和之前课程设计时遇到的情况是一样的！
	{
		printf("%d\n",num);
	}
	return 0;
}
*/
//还有一点关于AC题的，那就是输入和答案是分开的，AC的只检测答案！
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
