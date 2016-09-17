//Ignatius and the Princess I变形在于求出每一条路径的长度！
//Ignatius and the Princess I输出很屌！
//按照题目要求，还要记录下前驱，定义一个二维数组来记录？
//路径不能够重复,现在需要优化！ 
/*
#include<iostream>
#include<cstdio>
using namespace std;
const int MAX=120;//max要开大点，不然出现ACCESS_VIOLATION非法访问，即指针越界！！
const int SIZE=120;

typedef struct
{
	int i;//当前方块的行号
	int j;//当前方块的列号
	int di;//di记录下一可走方位的方位号
	int num;//记录迷宫mg[i][j]的值
}Stack;//栈定义

typedef struct {
   int x[MAX/2];
   int y[MAX/2];
   int num[MAX/2];
   int length;
   int time;
}Record;

Stack st[MAX];
Record rec[MAX/2];//记录路径

int mg[SIZE][SIZE];

int mgpath(int x1,int y1,int x2,int y2)//起点终点的坐标值
{
  int i,j,di,find,k=0;
  int m;
  int top=-1;//初始化栈指针
  top++;
  st[top].i=x1; st[top].j=y1; st[top].di=-1; st[top].num=mg[x1][y1];//记录下迷宫的值
  
  mg[x1][y1]=-1;//初始化，起点入栈

  while(top>-1)//栈不为空时循环
  {
	  i=st[top].i;
	  j=st[top].j; 
	  di=st[top].di;
      //绝妙一笔，记录下该方块的下一个可走方位，并且di只可以增，且小于4，可以保证不走曾经走过的路
	  if(i==x2 && j==y2)//找到了终点
	  {
		 //栈里面的就是路径，可以在这里记录下下标值

		  for(m=0,rec[k].time=0;m<=top;m++)
		  {
			  rec[k].x[m]=st[m].i;  rec[k].y[m]=st[m].j; rec[k].num[m]=st[m].num;
			  if(st[m].num==10)
			  rec[k].time=rec[k].time+1;//记录下这一条路径的长度
			  else
              rec[k].time=rec[k].time+st[m].num;
		  }
		  
		 
		  if(st[top].num!=10)//终点有怪物,这里一定要记住，不能判断mg[x2][y2]!=10,因为mg[x2][y2]=-1,因为入栈时将其标记为了-1
		 {
			 // cout<<"mg[x2][y2]="<<mg[x2][y2]<<endl;
		    rec[k].time=rec[k].time+st[top].num;//果然，问题出在m这里 
		  }
		  //我明白了，这是由于出栈的时候，并没有将里面的值删掉，因此st[top+1]可能取到0~10；
          
           
		  rec[k].length=top+1;//由于top从0开始
		  k++;
		  
		  mg[x2][y2]=st[top].num;//出栈，重新寻找另一条路径
		  top--;
          i=st[top].i; 
		  j=st[top].j;
		  di=st[top].di;
	  }
	  find=0;
	  while(di<4 && find==0)//算法最妙的地方
	  {
		  di++;//先加加,指向下一个方向!
		  switch(di)
		  {
			  case 0: i=st[top].i-1; j=st[top].j; break;
			  case 1: i=st[top].i; j=st[top].j+1; break;
			  case 2: i=st[top].i+1; j=st[top].j; break;
			  case 3: i=st[top].i; j=st[top].j-1; break;
		  }
		  if(mg[i][j]>0) find=1;//只要不为陷阱，就可以走	  
		  //很奇怪的问题，为什么等于0就不可以？ 
		  //只有一种可能，就是访问越界！导致错误！ 
	  }

	  if(find==1)//找到了下一个可走方块
	  {
		  st[top].di=di;//修改原栈顶元素的di值
		  top++;//下一个可走方块进栈
		  st[top].i=i; st[top].j=j; st[top].di=-1; st[top].num=mg[i][j];//进栈
		  mg[i][j]=-1;//走过的方块标记为-1，避免重复走到该方块
	  }
	  else//没有路径可走，就退栈
	  {
		  mg[st[top].i][st[top].j]=st[top].num;//让该位置变为其他路径可走方块
		  top--;
	  }

  }
  return k;//返回路径数目！
}

int main()
{
	int m,n;
	int i,j,k;
	char str[SIZE];//字符串数组
	int min,p;//记录起点终点的值

	while(scanf("%d %d",&m,&n)!=EOF )
	{
		 for(i=0;i<m;i++)//m行
		 {
            cin>>str;//输入字符串
			for(k=0;k<n;k++)//n列
			{
				if(str[k]=='.') mg[i][k]=10;
				if(str[k]=='X') mg[i][k]=-1;
				if(str[k]>='1' && str[k]<='9') mg[i][k]=str[k]-'0';
			}
		 }

		
		j=mgpath(0,0,m-1,n-1);//返回路径的长度	
		
        for(i=0,min=1000,p=0;i<j-1;i++)
		{
			cout<<rec[i].time<<endl;
			if(rec[i].time<min)
			{
				min=rec[i].time;
				p=i;//p用于记录耗时最小的路径的编号 
			}

		}
		

		if(j==0) //i肯定等于j
		cout<<"God please help our poor hero."<<endl;
		else
		{
			cout<<"It takes "<<min<<" seconds to reach the target position, let me show you the way."<<endl;
			for(i=0,k=0;i<rec[p].length-1;i++)
			{
				k++;
				if(rec[p].num[i]>=1 && rec[p].num[i]<=9)
				{
					for(int y=0;y<rec[p].num[i];y++)
					{
						cout<<k<<"s:FIGHT AT ("<<rec[p].x[i]<<','<<rec[p].y[i]<<')'<<endl;
						k++;
					}
				}
				cout<<k<<"s:"<<'('<<rec[p].x[i]<<','<<rec[p].y[i]<<')'<<"->("<<rec[p].x[i+1]<<','<<rec[p].y[i+1]<<')'<<endl;
			}
			if(rec[p].num[i]!=10)
			{
              k++;
			  cout<<k<<"s:FIGHT AT ("<<rec[p].x[i]<<','<<rec[p].y[i]<<')'<<endl;
            }
	}
	cout<<"FINISH"<<endl;	
	}
	return 0;
}
*/
//特郁闷啊，居然超时！难道不是用这种算法么？
//知道错误原因了！，要用宽搜，不能用深搜！
//用 宽搜+优先队列 找到的第一条路径绝对是最短路径，没办法，从新来过！！

#include<iostream>
#include<queue>
#include<stack>
#include<cstdio>
using namespace std;
const int SIZE=120;

struct Record 
{
    int i;
    int j;
    int cost;//总耗时 
    bool operator<(const Record &a) const
    {
        return cost>a.cost;
    }
}temp,temp1;

struct node
{
    int i,
	int	j;
	int num;
}pre[120][120];//前驱结点
 

int mg[SIZE][SIZE];//定义一个迷宫数组

int b[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int m,n;//迷宫大小，行列值 
int mins;

//最短路径的长度算是求出来了，接下来关键在于如何记录路径上的点

bool bfs(int x1,int y1,int x2,int y2)//bfs的算法算是写好了 
{
	  priority_queue<Record> q;
	  
	  int bx,by;
	  //int bx1,by1;
	  int flag[SIZE][SIZE];//标志数组最好放进来，这样每次调用函数时重新建立，会将里面的数据清0;
      memset(flag,0,sizeof(flag));//在使用flag数组的时候，最好先清一下0，不然会WA，我不知道他的测试数据是怎样的，但是不清0答案貌似也没有错误
	  //有一种解释，数组在未初始化的情况下，某个值是随机值，也就是说，可能某个flag取到1，这样的话，势必引起错误！
	  /*
		C语言中数组在没有初始化的情况下，各元素的值会怎样？

		不确定的值啊！！你知道不？？
		如：
			  你定义一个整形变量，而直接输出这个变量，你看看，是多少、？
			  知道了不？？
			   这个值是上次使用过这个地址的值，也、就是说你上次定义了个变量，系统分配一个地址给这个变量，
				  你赋了值给这个变量，就等于这个地址值的值是你赋值的那个值，你下次想分配一个变量，刚好系
				 统将这个变量分配的这个地址值是你上次使用的地址，如果你没初始化，那这个地址值的数值是你
				  上次使用过的值。。
		   说了好多，不知你听的明白不？？不过不重要，你只要记住定义时记得初始化就行了
		继续追问： 不好意思，请你再讲详细一点。 谢谢。
		补充回答：
		我不知道怎么说啊！！！
		   假如这样吧!制造商刚制造出来的硬盘内存里都没有东西的，就是说只有地址值：这个你懂吧，就是
				给地址编上序号，里面什么都没，如没有数值（0或1）。
		   后来你用这台电脑编写代码，定义了一个变量并赋值了（0或1）改写了这个地址值的内容，你写 完了代码就退出，可这个地址值的内容还是没变，除非你将这个变量另外赋值。
			后来你想编写代码时，你又定义了个变量，编编那么巧，系统帮你分配地址值，这次使用的地址值是你上次用的（上一个定义的变量的地址值），假如你的变量没初始化，那你这次使用的变量的数值就是你上次定义时的值。。。。。
 
		   说真的，我没办法再详细啦！！语言表达能力有限，你多看几遍我说的话吧
		   */

	  flag[x1][y1]=1;//走过得路径标记为1，表示不能再走 
	  temp1.i=x1;
	  temp1.j=y1;
	  temp1.cost=0;//起点的耗时为0 

	  q.push(temp1);//入队列 
	  while(!q.empty())//不是吧，直接就在这里完了
	  {

			 temp=q.top();//取队顶元素
			 q.pop();//出队列
			 
			 if(temp.i==x2 && temp.j==y2) 
			 { 
				mins=temp.cost;//直到终点的花费就是最少花费 
				return true;
			 } 
            // printf("出队列的元素为%d,%d\n",temp.i,temp.j);
			 for(int i=0;i<4;i++)
			 {

			    bx=temp.i+b[i][0];
			    by=temp.j+b[i][1];
				if(bx>=0 && bx<m && by>=0 && by<n && !flag[bx][by] && mg[bx][by]!=-1)
				{
					 temp1.i=bx;
                     temp1.j=by;
				     temp1.cost=temp.cost+mg[bx][by];
                   // printf("入队列的元素是%d,%d\n",bx,by);
					pre[bx][by].i=temp.i;//bx,by是现在结点的下标值
					pre[bx][by].j=temp.j;//用来记录前驱结点的下标值
					pre[bx][by].num=mg[temp.i][temp.j];
                   // printf("pre[%d][%d]=(%d,%d),可是事实是(%d,%d)\n",bx,by,temp.i,temp.j,pre[bx][by].i,pre[bx][by].j);
                    
                   // printf("pre[%d][%d]的前驱是(%d,%d)\n",bx,by,temp.i ,temp.j );//每一次入队列的数都不一样
                     
                    //printf("(%d,%d)->(%d,%d)\n",bx,by,temp.i,temp.j);
					q.push(temp1);//入队列！


				    flag[bx][by]=1;//标记为1;走过了之后就不能再走了！
				/*	for(;;)
					{
						bx1=bx;
						by1=by;
						if(bx==0 && by==0) break;
						printf("(%d,%d)->",bx1,by1);
						bx=pre[bx1][by1].i;
						by=pre[bx1][by1].j;//追踪这么久，总算找出元凶了！
					//看看我原来的语句，1.bx=pre[bx][by]; 2.by=pre[bx][by];执行第一句时，bx已经改变，也就是说前一个pre[bx][by]和后一个pre[bx][by]可能不为同一个数
					//哥就这样傻傻地被这个小错误纠结了差不多一天，深深感受到崩溃以及挫败感！他娘的！太坑爹了！以后一定要细心，这样的错误再犯几次，会死人的！
					}
					printf("(%d,%d)\n",bx,by);*/
				 }//if	 	   
			}//for  
		 }//while
	 return false;         
  } 
  
void print()
{
	int k=1,i;
	int x1,y1;
	int x2,y2;
    stack<node> s;
	node temp,temp1;
    temp1.i=m-1; temp1.j=n-1; temp1.num=mg[m-1][n-1];
	s.push(temp1);
	for(x1=m-1,y1=n-1;;)//从终点开始，一级级地向前压栈
	{
		x2=x1;
	    y2=y1;
	    //cout<<'('<<x1<<','<<y1<<')'<<endl;//输出x1，y1的值，应该说这里不应该出现错误啊！
	    s.push(pre[x2][y2]);//不断的压栈
		x1=pre[x2][y2].i;//不断地向前搜寻前结点
		y1=pre[x2][y2].j;//一直压到了x1=0,y1=0;
		if(x1==0 && y1==0) break;
	}
    while(!s.empty())
	{
		if(s.size()-1==0 && s.top().num==1) break;	
		temp=s.top();
		s.pop();
		if(s.size()>0)
		temp1=s.top();
		if(temp.num==1)
		printf("%ds:(%d,%d)->(%d,%d)\n",k++,temp.i,temp.j,temp1.i,temp1.j);
		else
		{
			for(i=1;i<temp.num;i++)
			printf("%ds:FIGHT AT (%d,%d)\n",k++,temp.i,temp.j);
			if(s.size()>0)
			printf("%ds:(%d,%d)->(%d,%d)\n",k++,temp.i,temp.j,temp1.i,temp1.j);
		}

	}
}

/*void print()
{
    stack<node> S;
    node temp,temp1;
	temp=pre[m-1][n-1];
	temp1.i=m-1; temp1.j=n-1; temp1.num=mins;
    S.push(temp1);
    while(temp.i!=0||temp.j!=0)
    {  
        S.push(temp);
        temp=pre[temp.i][temp.j];
    }
	
    int t=1;
    while(!S.empty())
    {
        temp=S.top();
        S.pop();
        if(mg[temp.i][temp.j]==1)
            printf("%ds:(%d,%d)->(%d,%d)\n",t++,pre[temp.i][temp.j].i,pre[temp.i][temp.j].j,temp.i,temp.j);
        else 
		{
            printf("%ds:(%d,%d)->(%d,%d)\n",t++,pre[temp.i][temp.j].i,pre[temp.i][temp.j].j,temp.i,temp.j);
            int k=mg[temp.i][temp.j]-1;
            while(k--)
            printf("%ds:FIGHT AT (%d,%d)\n",t++,temp.i,temp.j);
        }
    }
    
    return ;
}*/
int main()
{
    
	int i,k,x1,y1;
	char str[SIZE];//字符串数组
	while(scanf("%d %d",&m,&n)>0)
	{
		 for(i=0;i<m;i++)//m行
		 {
            cin>>str;//输入字符串
			for(k=0;k<n;k++)//n列
			{
				if(str[k]=='.') mg[i][k]=1;
				else if(str[k]=='X') mg[i][k]=-1;
				else mg[i][k]=str[k]-'0'+1;
					
			}
		 }
		 /*for(i=0;i<m;i++)
		 {
			 for(k=0;k<n;k++)
				 cout<<mg[i][k]<<" ";
			 cout<<endl;
		 }//map数组变化了，没有问题！*/
		 //memset(flag,0,sizeof(flag));//关键在于这个句子，我提交了几次都WA，居然是因为少了这个句子
         if(bfs(0,0,m-1,n-1))
		 {
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",mins);
            print();
		 }
	     else
	     printf("God please help our poor hero.\n");
	     printf("FINISH\n");
	}
  return 0;
}

