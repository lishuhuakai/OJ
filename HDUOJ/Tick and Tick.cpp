/*****************************
12h=43200s;
v=6 度/秒(秒针速度)
v'=1/10 度/秒 (分针速度)
v''=1/120 度/秒 (时针速度)
v1=59/10 度/秒(秒针和分针速度差)
v2=719/120 度/秒(秒针和时针速度差)
v3=11/120 度/秒(分针和时针速度差)
******************************/
#include<iostream>
#include<cstdio>
using namespace std;

inline double max(double a,double b,double c) 
{ 
	a= a > b ? a: b; 
	a= a > c ? a: c; 
	return a; 
} 

inline double min(double a,double b,double c) 
{ 
	a= a < b ? a: b; 
	a= a < c ? a: c; 
	return a; 
} 

int main()
{
	int i,j;
    double dsm[1444],dsh[1444],dmh[26];//用于记录表的指针距离d的起始与终结时间
	double d,sum,x,y;//注意精度问题，d应为double类型，不应为int类型，否则会出错
    double sm,mh,sh;
	int smf[2],mhf[2],shf[2];
	sm=3600.0000/59;//秒针与分针重合一次所需时间
	sh=43200.0000/719;//秒针与时针重合一次所需时间
	mh=43200.0000/11;//时针与分针重合一次所需时间
	while(cin>>d && d!=-1)
	{
		sum=0;x=0;y=0;
		dsm[0]=(10*d)/59;//记录第一次秒针与分针距离d的时间
		dsh[0]=(120*d)/719;//记录第一次秒针与时针距离d的时间
		dmh[0]=(120*d)/11;//记录第一次分针与时针距离d的时间
		dsm[1]=sm-dsm[0];//记录第一次秒针与时针距离开始小于d的时间
		dsh[1]=sh-dsh[0];//记录第一次秒针与时针距离开始小于d的时间
		dmh[1]=mh-dmh[0];//记录第一次秒针与时针距离开始小于d的时间

		for(i=2,j=3;;i+=2,j+=2)
		{
			dsm[i]=dsm[i-2]+sm;//下一次距离大于等于d的时间
			dsm[j]=dsm[j-2]+sm;//下一次距离小于d的时间
			if(dsm[i]>43200 && dsm[j]>43200)  break;
		}//分别记录下每一次距离d和开始小于d的时间

         for(i=2,j=3;;i+=2,j+=2)
		{
			dsh[i]=dsh[i-2]+sh;//下一次距离大于等于d的时间
			dsh[j]=dsh[j-2]+sh;//下一次距离小于d的时间
			if(dsh[i]>43200 && dsh[j]>43200)  break;
		}//分别记录下每一次距离d和开始小于d的时间

        for(i=2,j=3;;i+=2,j+=2)
		{
			dmh[i]=dmh[i-2]+mh;//下一次距离大于等于d的时间
			dmh[j]=dmh[j-2]+mh;//下一次距离小于d的时间
			if(dmh[i]>43200 && dmh[j]>43200)  break;
		}//分别记录下每一次距离d和开始小于d的时间

        smf[0]=mhf[0]=shf[0]=0;
        smf[1]=mhf[1]=shf[1]=1;//初始化，以第一次为基点
		while(y<=43200 && x<=43200)
		{
			x=max(dsm[smf[0]],dsh[shf[0]],dmh[mhf[0]]);//起点找大者
			y=min(dsm[smf[1]],dsh[shf[1]],dmh[mhf[1]]);//终点找小者
			if(x<y) sum+=y-x;//一段一段的累加满足的时间
			if(y==dsm[smf[1]]) { smf[0]+=2; smf[1]+=2; }//转向下一次
            if(y==dsh[shf[1]]) { shf[0]+=2; shf[1]+=2; }//转向下一次
            if(y==dmh[mhf[1]]) { mhf[0]+=2; mhf[1]+=2; }//转向下一次
		}
		printf("%.3f\n",sum/432); //实际上只计算了12个小时，不过比例可以替代一天
	}
	return 0;
}
