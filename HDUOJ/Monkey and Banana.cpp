#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

struct block{
       int area;
       int height;
	   int width;
	   int length;
       };
       
bool cmp(block &a,block &b)
{
     return a.area>b.area;
 } 
    
int main()
{
    int kinds;
	int i,j,l,w,h,s=1;
	int max;
	int k;
    block b[100];
    vector<int> hdp(300);
    
    block temp;
    while(1)
    {
	   k=0;
	  cin>>kinds;
      if(kinds==0) break;
      for(i=0;i<kinds;i++)
	  {
      cin>>l>>w>>h;
	  temp.width=l;temp.length=w;
      temp.area=l*w; temp.height=h;
      b[k++]=temp;
      temp.width=l;temp.length=h;
      temp.area=l*h; temp.height=w;
      b[k++]=temp;
      temp.width=h;temp.length=w;
      temp.area=h*w; temp.height=l;
      b[k++]=temp;
      }
	  //������ˣ��ϸ��С���Ǿ���ÿһ���ߣ�������Ҫ�ȵ��µ�С�������ܵ��ڣ�
       sort(b,b+kinds*3,cmp);//����,��������Ӵ�С����
        hdp[0]=b[0].height;//��������������ש��Ϊ�ף�����ߵĸ߶�Ϊ���ĸ߶� 
       //�������Ƕ�̬�滮�ˣ�
       //���鷽��Ϊ hdp[i]=max{hdp[j]+b[i].height,b[i].height|b[j].area>b[i].area,j=0,1,����i-1};
        for(i=1;i<kinds*3;i++)
        {
         hdp[i]=b[i].height;
         for(j=0;j<i;j++)//����������b[i].area;��ôһ�����������⣡
		 {
         if( (b[i].width<b[j].width && b[i].length<b[j].length)||(b[i].width<b[j].length && b[i].length<b[j].width) )
			if( hdp[j]+b[i].height>hdp[i])//Ѱ������ֵ
              hdp[i]=hdp[j]+b[i].height;
		 }
        }
		max=0;
		for(i=0;i<kinds*3;i++)
			if(hdp[i]>max)
				max=hdp[i];
      printf("Case %d: maximum height = %d\n",s,max);
	  s++;
     }
    return 0;
}
