//刚开始做题，先水几道题，巩固巩固状态
//粗枝大叶的老毛病又犯了，一定要细致
#include<iostream>
using namespace std;

struct Coord//坐标
{
	double x,y;
};

struct Segment//一条直线上的两个点
{
	Coord a,b;
};

bool Judge(Coord &a,Coord &b,Coord &c,Coord &d)
{
	if(!(min(a.x,b.x)<=max(c.x,d.x) && min(c.y,d.y)<=max(a.y,b.y)&&
		min(c.x,d.x)<=max(a.x,b.x) && min(a.y,b.y)<=max(c.y,d.y)))//这里的确如此，这一步是判定两矩形是否相交
		//特别要注意一个矩形含于另一个矩形之内的情况
	return false;
    double u,v,w,z;//分别记录两个向量
    u=(c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y);
	v=(d.x-a.x)*(b.y-a.y)-(b.x-a.x)*(d.y-a.y);
	w=(a.x-c.x)*(d.y-c.y)-(d.x-c.x)*(a.y-c.y);
	z=(b.x-c.x)*(d.y-c.y)-(d.x-c.x)*(b.y-c.y);
	return (u*v<=0.00000001 && w*z<=0.00000001);
}

int main()
{
	int n;
	Segment str[101];
	while(cin>>n && n!=0)
	{
		int count=0;
		for(int i=0;i<n;i++)
		{
			cin>>str[i].a.x>>str[i].a.y>>str[i].b.x>>str[i].b.y;
		}
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(Judge(str[i].a,str[i].b,str[j].a,str[j].b)) count++;
		cout<<count<<endl;
	}
	return 0;
}