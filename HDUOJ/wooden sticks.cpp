//�ܺõ�һ���⣬���Ƕ�̬�滮��
//�Լ�������һ�룡
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
				if(size[i].w<=size[k].w && size[i].l<=size[k].l)//���û�г߶ȣ���һ�㲻�ԣ�
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
					  //cout<<"���е����˴���"<<endl;
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
							  cout<<"�ɹ����룡"<<endl;
							  flag=1; break;
						  }
						  //cout<<"�ѵ���Խ�磿"<<endl;
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

//���첻�ô��룬�о��˻��ˣ��ִ������ˣ�

#include<iostream>
#include<algorithm>
using namespace std;

struct SIZE
{
	int l;
	int w;
}sticks[5005];
int flag[5005];

bool cmp(const SIZE &a,const SIZE &b)//����������
{//д��������ʱ��Ҫ�ر��С�ģ�
	//if(a.w!=b.w)//����д���ˣ������ʾ����������ȣ����ճ����ţ����������ȣ����������ţ���û���壡��
	if(a.l!=b.l)
		return a.l>b.l;//���Ȳ���ʱ���ճ����ţ��Ӵ�С��
	else
		return a.w>b.w;//�������ʱ���ٰ��������Ӵ�С����
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
int cmp(SIZE a,SIZE b)//�ȽϺ���
{
  if(a.l==b.l)//�Ȱ������ţ�������ͬʱ����������
  return a.w<b.w;
  else
  return a.l<b.l;
}
*/
bool cmp(const SIZE &a,const SIZE &b)//����������
{
	if(a.l!=b.l)
		return a.l<b.l;//���ճ����ţ��Ӵ�С��
	else
		return a.w<b.w;//�������ʱ���ٰ��������Ӵ�С����
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

     sort(sticks+1,sticks+n+1,cmp);//����

     int s=0; 
     int min;

     for(int i=1;i<=n;i++)
     {
       if(flag[i]) continue;//flag[i]�������
       min=sticks[i].w;
       for(int j=i+1;j<=n;j++)//�ϸ����˵���ⲻ�Ƕ�̬�滮��
       {
         if(flag[j]==0&&min<=sticks[j].w)//û�б���ǹ��Լ���minҪ��
         {
          flag[j]=1;//�����
          min=sticks[j].w;//min���ڼ�¼��С��ֵ
         }
       }
       s++;
     }
     cout<<s<<endl;
   }
 return 0; 
}




hdu 1051 Wooden Sticks
��һ����ά�����������ٿ��Էֳɼ������½���������a<=bΪa.x<=b.x&&a.y<=b.y����
�����ö��̰�ģ������ܵİ�ÿһ������������Ӵ��ĺ��档û�еĻ������һ���Ӵ������ͳ�Ƹ������ɡ�
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