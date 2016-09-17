//很好的一道题，又是动态规划！
//自己认真想一想！
/*
#include<iostream>
#include<cstdio>
using namespace std;

struct SIZE
{
	int w;
	int l;
}size[5001];

int main()
{
	int n,min,flag,cases;
	int i,j,k;
	while(scanf("%d",&cases)!=EOF)
	{   
		for(j=0;j<cases;j++)
		{
			cin>>n;
			for(i=1;i<=n;i++)
			cin>>size[i].w>>size[i].l;
			min=1;
			for(i=2;i<=n;i++)
			{
				flag=0;
				for(k=1;k<i;k++)
				if(size[i].w<=size[k].w && size[i].l<=size[k].l)//这边没有尺度！有一点不对！
				{
					flag=1; break;
				}
				if(flag==0) min=min+1;
			}
			cout<<min<<endl;
		}
	}

	return 0;
}
*/
/*
#include<iostream>
#include<list>
using namespace std;

struct SIZE
{
	int w;
	int l;
};

int main()
{
  int n,min,flag,cases;
  int i,j;
  SIZE temp;
  while(scanf("%d",&cases)!=EOF)
  {
        for(j=0;j<cases;j++)
		{
			cin>>n;
			list<SIZE> l;
			cin>>temp.w>>temp.l;
			l.push_back(temp);
			list<SIZE>::iterator iter;
			//iter=l.begin();

			min=1;
			for(i=2;i<=n;i++)
			{
				  cin>>temp.w>>temp.l;
				  iter=l.begin();
				  cout<<iter->w<<"  1  "<<iter->l<<" i= "<<i<<endl;
				  flag=0;

				  while(iter!=l.end())
				  {
					  //cout<<"运行到过此处！"<<endl;
					  //cout<<iter->w<<"  4  "<<iter->l<<endl;
					  //cout<<temp.w<<"   4  "<<temp.l<<endl;
					  //cout<<"l.size()="<<l.size()<<endl;
					  if(iter->w > temp.w && iter->l >temp.l )
					  {
						  //cout<<iter==l.end()<<endl;
						  if(iter==l.end())
						  {    
							  //iter++;
							  cout<<"zheli"<<endl;
							  l.push_back(temp);
							  cout<<"成功插入！"<<endl;
							  flag=1; break;
						  }
						  //cout<<"难道是越界？"<<endl;
						  iter++;
						 // j++;
						  cout<<iter->w<<"  2  "<<iter->l<<endl;
						  continue;
						  //  flag=1; break;
					  }
					  else
					  if(iter->w < temp.w && iter->l < temp.l)
					  {
						  cout<<iter->w<<"  3  "<<iter->l<<endl;
						  l.insert(iter,temp);  flag=1; break;
					  }
					 iter++;
					 //j++;
				  }
				  if(flag==0) 
				  {
					  l.push_back(temp);  min=min+1;
				      cout<<"min="<<min<<endl;
				  }
			}
			cout<<min<<endl;
		}
  }
	return 0;
}
*/

//几天不敲代码，感觉退化了！又粗心死了！

#include<iostream>
#include<algorithm>
using namespace std;

struct SIZE
{
	int l;
	int w;
}sticks[5005];
int flag[5005];

bool cmp(const SIZE &a,const SIZE &b)//这里是排序！
{//写排序函数的时候要特别的小心！
	//if(a.w!=b.w)//这里写错了，这里表示如果重量不等，按照长度排，如果重量相等，则按照重量排！（没意义！）
	if(a.l!=b.l)
		return a.l>b.l;//长度不等时按照长度排，从大到小排
	else
		return a.w>b.w;//长度相等时，再按照重量从大到小排列
}

int main()
{
	int n,min,cases;
	int i,j,s;
	

	cin>>cases; 
	for(j=0;j<cases;j++)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>sticks[i].l>>sticks[i].w;
			flag[i]=0;
		}
		sort(sticks,sticks+n,cmp);

		s=0;
		for(i=0;i<n;i++)
		{
			if(flag[i]) continue;
			min=sticks[i].w;

			for(int j=i+1;j<n;j++)
			{
				if(min>=sticks[j].w && !flag[j])
				{
					min=sticks[j].w;
					flag[j]=1;
				}
			}
			s++;
		}
		cout<<s<<endl;
	}
	//system("pause");
	return 0;
}



#include<iostream>
#include<algorithm>
using namespace std;

struct SIZE{
  int l;
  int w;
}sticks[5005];

int flag[5005];
/*
int cmp(SIZE a,SIZE b)//比较函数
{
  if(a.l==b.l)//先按长度排，长度相同时按照重量排
  return a.w<b.w;
  else
  return a.l<b.l;
}
*/
bool cmp(const SIZE &a,const SIZE &b)//这里是排序！
{
	if(a.l!=b.l)
		return a.l<b.l;//按照长度排，从大到小排
	else
		return a.w<b.w;//长度相等时，再按照重量从大到小排列
}

int main()
{
   int cases;
   cin>>cases;
   while(cases--)
   {
     int n;
     cin>>n;
     for(int i=1;i<=n;i++)
     {
      cin>>sticks[i].l>>sticks[i].w;
      flag[i]=0;
     }

     sort(sticks+1,sticks+n+1,cmp);//排序

     int s=0; 
     int min;

     for(int i=1;i<=n;i++)
     {
       if(flag[i]) continue;//flag[i]标记数组
       min=sticks[i].w;
       for(int j=i+1;j<=n;j++)//严格的来说，这不是动态规划！
       {
         if(flag[j]==0&&min<=sticks[j].w)//没有被标记过以及比min要大
         {
          flag[j]=1;//做标记
          min=sticks[j].w;//min用于记录最小的值
         }
       }
       s++;
     }
     cout<<s<<endl;
   }
 return 0; 
}




hdu 1051 Wooden Sticks
求一个二维的数组中最少可以分成几个非下降串（定义a<=b为a.x<=b.x&&a.y<=b.y）。
排序后枚举贪心，尽可能的把每一个点放在最大的子串的后面。没有的话就添加一个子串，最后统计个数即可。
#include<stdio.h>
#include<iostream>
using namespace std;

int cmp(const void *a,const void *b)
{
    if(((int*)a)[0]==((int*)b)[0])
     return ((int*)a)[1]-((int*)b)[1];
    return ((int*)a)[0]-((int*)b)[0];
}

int a[5005][2];
int b[5005];
int main()
{
    int i,j,n,m,k,l,p;
    scanf("%d",&p);
    while(p--)
    {
       scanf("%d",&n);
       for(i=1;i<=n;i++)
        scanf("%d%d",&a[i][0],&a[i][1]);
       qsort(&a[1],n,sizeof(int)*2,cmp);
       l=1;b[1]=a[1][1];
       for(i=2;i<=n;i++)
       {
          for(j=1;j<=l;j++)
           if(a[i][1]>=b[j]) 
            {b[j]=a[i][1];break;}
          if(j>l)
          {
             b[j]=a[i][1];
             l++;
          }    
       }
       printf("%d\n",l);
    }
}