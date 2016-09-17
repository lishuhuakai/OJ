//超级逆天的迷宫算法，我真心服了！
/********************************************
di所指的方位：
0 上；
1 右；
2 下；
3 左；
********************************************/
#include<iostream>
using namespace std;
const int MAX=100;//max要开大点，不然出现ACCESS_VIOLATION非法访问，即指针越界！！
const int SIZE=8;

typedef struct
{
	int i;//当前方块的行号
	int j;//当前方块的列号
	int di;//di记录下一可走方位的方位号
}Stack;//栈定义

Stack st[MAX];

int mg[SIZE][SIZE];
int length[MAX];

int mgpath(int x1,int y1,int x2,int y2)//起点终点的坐标值
{
  int i,j,di,find,k=-1;
  int top=-1;//初始化栈指针
  top++;
  st[top].i=x1; st[top].j=y1; st[top].di=-1; mg[x1][y1]=-1;//初始化，起点入栈
  while(top>-1)//栈不为空时循环
  {
	  i=st[top].i; j=st[top].j; 
	  di=st[top].di;//绝妙一笔，记录下该方块的下一个可走方位，并且di只可以增，且小于4，可以保证不走曾经走过的路
	  if(i==x2 && j==y2)//找到了终点
	  {
		  k++;
		  length[k]=top;//记录下这条路径的长度
		  mg[x2][y2]=2;
		  top--;//出栈，重新寻找另一条路径
          i=st[top].i; j=st[top].j; di=st[top].di;
	  }
	  find=0;
	  while(di<4 && find==0)//算法最妙的地方
	  {
		  di++;//先加加，指向下一个方向!
		  switch(di)
		  {
			  case 0: i=st[top].i-1; j=st[top].j; break;
			  case 1: i=st[top].i; j=st[top].j+1; break;
			  case 2: i=st[top].i+1; j=st[top].j; break;
			  case 3: i=st[top].i; j=st[top].j-1; break;
		  }
		  if(mg[i][j]==2) find=1;//关于越界！mg数组中除了已经用到的，其余的值均为0；
	  }
	  if(find==1)//找到了下一个可走方块
	  {
		  st[top].di=di;//修改原栈顶元素的di值
		  top++;//下一个可走方块进栈
		  st[top].i=i; st[top].j=j; st[top].di=-1;
		  mg[i][j]=-1;//走过的方块标记为-1，避免重复走到该方块
	  }
	  else//没有路径可走，就退栈
	  {
		  mg[st[top].i][st[top].j]=2;//让该位置变为其他路径可走方块
		  top--;
	  }
  }
  return k+1;
}

int main()
{
	int m,n,time;
	int i,j,k;
	char str[SIZE];//字符串数组
	int a,b,c,d;//记录起点终点的值
	while(cin>>m>>n>>time && (m!=0 && n!=0 && time!=0))
	{
	//	cout<<"m="<<m<<"  "<<"n="<<n<<"   "<<"time="<<time<<endl;
		 for(i=0;i<m;i++)//m行
		 {
            cin>>str;//输入字符串
			for(k=0;k<n;k++)//n列
			{
				if(str[k]=='S') 	
				{ 
					a=i; b=k; 
				}
				if(str[k]=='D')     
				{ 
					c=i; d=k; 
				}
				switch(str[k])
				{   
				    case 'S' : 
					case 'D':
					case  '.':  mg[i][k]=2;   break;
					case 'X' :   mg[i][k]=-1;  break;	
				}
			}
		 }
		 /*
		 for(i=0;i<m;i++)
		 {
			 for(j=0;j<n;j++)
			 cout<<mg[i][j]<<"   ";
			 cout<<endl;
		 }
		 */
		 /*
		 cout<<"a="<<a<<endl;
		 cout<<"b="<<b<<endl;
		 cout<<"c="<<c<<endl;
		 cout<<"d="<<d<<endl;
		 */
		j=mgpath(a,b,c,d);
		//cout<<"j="<<j<<endl;
		for(i=0;i<j;i++)
		{
			//cout<<length[i]<<endl;
			if(length[i]==time) 
			{
			 cout<<"YES"<<endl;
			 break;
			}
		}
		if(i==j) 
		cout<<"NO"<<endl;
	}
	return 0;
}

