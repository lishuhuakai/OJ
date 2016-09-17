//�տ�ʼ���⣬��ˮ�����⣬���̹���״̬
//��֦��Ҷ����ë���ַ��ˣ�һ��Ҫϸ��
#include<iostream>
using namespace std;

struct Coord//����
{
	double x,y;
};

struct Segment//һ��ֱ���ϵ�������
{
	Coord a,b;
};

bool Judge(Coord &a,Coord &b,Coord &c,Coord &d)
{
	if(!(min(a.x,b.x)<=max(c.x,d.x) && min(c.y,d.y)<=max(a.y,b.y)&&
		min(c.x,d.x)<=max(a.x,b.x) && min(a.y,b.y)<=max(c.y,d.y)))//�����ȷ��ˣ���һ�����ж��������Ƿ��ཻ
		//�ر�Ҫע��һ�����κ�����һ������֮�ڵ����
	return false;
    double u,v,w,z;//�ֱ��¼��������
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