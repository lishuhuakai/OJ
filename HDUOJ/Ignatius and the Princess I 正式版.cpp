//Ignatius and the Princess I�����������ÿһ��·���ĳ��ȣ�
//Ignatius and the Princess I����܌ţ�
//������ĿҪ�󣬻�Ҫ��¼��ǰ��������һ����ά��������¼��
//·�����ܹ��ظ�,������Ҫ�Ż��� 
/*
#include<iostream>
#include<cstdio>
using namespace std;
const int MAX=120;//maxҪ����㣬��Ȼ����ACCESS_VIOLATION�Ƿ����ʣ���ָ��Խ�磡��
const int SIZE=120;

typedef struct
{
	int i;//��ǰ������к�
	int j;//��ǰ������к�
	int di;//di��¼��һ���߷�λ�ķ�λ��
	int num;//��¼�Թ�mg[i][j]��ֵ
}Stack;//ջ����

typedef struct {
   int x[MAX/2];
   int y[MAX/2];
   int num[MAX/2];
   int length;
   int time;
}Record;

Stack st[MAX];
Record rec[MAX/2];//��¼·��

int mg[SIZE][SIZE];

int mgpath(int x1,int y1,int x2,int y2)//����յ������ֵ
{
  int i,j,di,find,k=0;
  int m;
  int top=-1;//��ʼ��ջָ��
  top++;
  st[top].i=x1; st[top].j=y1; st[top].di=-1; st[top].num=mg[x1][y1];//��¼���Թ���ֵ
  
  mg[x1][y1]=-1;//��ʼ���������ջ

  while(top>-1)//ջ��Ϊ��ʱѭ��
  {
	  i=st[top].i;
	  j=st[top].j; 
	  di=st[top].di;
      //����һ�ʣ���¼�¸÷������һ�����߷�λ������diֻ����������С��4�����Ա�֤���������߹���·
	  if(i==x2 && j==y2)//�ҵ����յ�
	  {
		 //ջ����ľ���·���������������¼���±�ֵ

		  for(m=0,rec[k].time=0;m<=top;m++)
		  {
			  rec[k].x[m]=st[m].i;  rec[k].y[m]=st[m].j; rec[k].num[m]=st[m].num;
			  if(st[m].num==10)
			  rec[k].time=rec[k].time+1;//��¼����һ��·���ĳ���
			  else
              rec[k].time=rec[k].time+st[m].num;
		  }
		  
		 
		  if(st[top].num!=10)//�յ��й���,����һ��Ҫ��ס�������ж�mg[x2][y2]!=10,��Ϊmg[x2][y2]=-1,��Ϊ��ջʱ������Ϊ��-1
		 {
			 // cout<<"mg[x2][y2]="<<mg[x2][y2]<<endl;
		    rec[k].time=rec[k].time+st[top].num;//��Ȼ���������m���� 
		  }
		  //�������ˣ��������ڳ�ջ��ʱ�򣬲�û�н������ֵɾ�������st[top+1]����ȡ��0~10��
          
           
		  rec[k].length=top+1;//����top��0��ʼ
		  k++;
		  
		  mg[x2][y2]=st[top].num;//��ջ������Ѱ����һ��·��
		  top--;
          i=st[top].i; 
		  j=st[top].j;
		  di=st[top].di;
	  }
	  find=0;
	  while(di<4 && find==0)//�㷨����ĵط�
	  {
		  di++;//�ȼӼ�,ָ����һ������!
		  switch(di)
		  {
			  case 0: i=st[top].i-1; j=st[top].j; break;
			  case 1: i=st[top].i; j=st[top].j+1; break;
			  case 2: i=st[top].i+1; j=st[top].j; break;
			  case 3: i=st[top].i; j=st[top].j-1; break;
		  }
		  if(mg[i][j]>0) find=1;//ֻҪ��Ϊ���壬�Ϳ�����	  
		  //����ֵ����⣬Ϊʲô����0�Ͳ����ԣ� 
		  //ֻ��һ�ֿ��ܣ����Ƿ���Խ�磡���´��� 
	  }

	  if(find==1)//�ҵ�����һ�����߷���
	  {
		  st[top].di=di;//�޸�ԭջ��Ԫ�ص�diֵ
		  top++;//��һ�����߷����ջ
		  st[top].i=i; st[top].j=j; st[top].di=-1; st[top].num=mg[i][j];//��ջ
		  mg[i][j]=-1;//�߹��ķ�����Ϊ-1�������ظ��ߵ��÷���
	  }
	  else//û��·�����ߣ�����ջ
	  {
		  mg[st[top].i][st[top].j]=st[top].num;//�ø�λ�ñ�Ϊ����·�����߷���
		  top--;
	  }

  }
  return k;//����·����Ŀ��
}

int main()
{
	int m,n;
	int i,j,k;
	char str[SIZE];//�ַ�������
	int min,p;//��¼����յ��ֵ

	while(scanf("%d %d",&m,&n)!=EOF )
	{
		 for(i=0;i<m;i++)//m��
		 {
            cin>>str;//�����ַ���
			for(k=0;k<n;k++)//n��
			{
				if(str[k]=='.') mg[i][k]=10;
				if(str[k]=='X') mg[i][k]=-1;
				if(str[k]>='1' && str[k]<='9') mg[i][k]=str[k]-'0';
			}
		 }

		
		j=mgpath(0,0,m-1,n-1);//����·���ĳ���	
		
        for(i=0,min=1000,p=0;i<j-1;i++)
		{
			cout<<rec[i].time<<endl;
			if(rec[i].time<min)
			{
				min=rec[i].time;
				p=i;//p���ڼ�¼��ʱ��С��·���ı�� 
			}

		}
		

		if(j==0) //i�϶�����j
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
//�����ư�����Ȼ��ʱ���ѵ������������㷨ô��
//֪������ԭ���ˣ���Ҫ�ÿ��ѣ����������ѣ�
//�� ����+���ȶ��� �ҵ��ĵ�һ��·�����������·����û�취��������������

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
    int cost;//�ܺ�ʱ 
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
}pre[120][120];//ǰ�����
 

int mg[SIZE][SIZE];//����һ���Թ�����

int b[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int m,n;//�Թ���С������ֵ 
int mins;

//���·���ĳ�������������ˣ��������ؼ�������μ�¼·���ϵĵ�

bool bfs(int x1,int y1,int x2,int y2)//bfs���㷨����д���� 
{
	  priority_queue<Record> q;
	  
	  int bx,by;
	  //int bx1,by1;
	  int flag[SIZE][SIZE];//��־������÷Ž���������ÿ�ε��ú���ʱ���½������Ὣ�����������0;
      memset(flag,0,sizeof(flag));//��ʹ��flag�����ʱ���������һ��0����Ȼ��WA���Ҳ�֪�����Ĳ��������������ģ����ǲ���0��ò��Ҳû�д���
	  //��һ�ֽ��ͣ�������δ��ʼ��������£�ĳ��ֵ�����ֵ��Ҳ����˵������ĳ��flagȡ��1�������Ļ����Ʊ��������
	  /*
		C������������û�г�ʼ��������£���Ԫ�ص�ֵ��������

		��ȷ����ֵ��������֪��������
		�磺
			  �㶨��һ�����α�������ֱ���������������㿴�����Ƕ��١���
			  ֪���˲�����
			   ���ֵ���ϴ�ʹ�ù������ַ��ֵ��Ҳ������˵���ϴζ����˸�������ϵͳ����һ����ַ�����������
				  �㸳��ֵ������������͵��������ֵַ��ֵ���㸳ֵ���Ǹ�ֵ�����´������һ���������պ�ϵ
				 ͳ�������������������ֵַ�����ϴ�ʹ�õĵ�ַ�������û��ʼ�����������ֵַ����ֵ����
				  �ϴ�ʹ�ù���ֵ����
		   ˵�˺ö࣬��֪���������ײ�������������Ҫ����ֻҪ��ס����ʱ�ǵó�ʼ��������
		����׷�ʣ� ������˼�������ٽ���ϸһ�㡣 лл��
		����ش�
		�Ҳ�֪����ô˵��������
		   ����������!�����̸����������Ӳ���ڴ��ﶼû�ж����ģ�����˵ֻ�е�ֵַ������㶮�ɣ�����
				����ַ������ţ�����ʲô��û����û����ֵ��0��1����
		   ����������̨���Ա�д���룬������һ����������ֵ�ˣ�0��1����д�������ֵַ�����ݣ���д ���˴�����˳����������ֵַ�����ݻ���û�䣬�����㽫����������⸳ֵ��
			���������д����ʱ�����ֶ����˸������������ô�ɣ�ϵͳ��������ֵַ�����ʹ�õĵ�ֵַ�����ϴ��õģ���һ������ı����ĵ�ֵַ����������ı���û��ʼ�����������ʹ�õı�������ֵ�������ϴζ���ʱ��ֵ����������
 
		   ˵��ģ���û�취����ϸ���������Ա���������ޣ���࿴������˵�Ļ���
		   */

	  flag[x1][y1]=1;//�߹���·�����Ϊ1����ʾ�������� 
	  temp1.i=x1;
	  temp1.j=y1;
	  temp1.cost=0;//���ĺ�ʱΪ0 

	  q.push(temp1);//����� 
	  while(!q.empty())//���ǰɣ�ֱ�Ӿ�����������
	  {

			 temp=q.top();//ȡ�Ӷ�Ԫ��
			 q.pop();//������
			 
			 if(temp.i==x2 && temp.j==y2) 
			 { 
				mins=temp.cost;//ֱ���յ�Ļ��Ѿ������ٻ��� 
				return true;
			 } 
            // printf("�����е�Ԫ��Ϊ%d,%d\n",temp.i,temp.j);
			 for(int i=0;i<4;i++)
			 {

			    bx=temp.i+b[i][0];
			    by=temp.j+b[i][1];
				if(bx>=0 && bx<m && by>=0 && by<n && !flag[bx][by] && mg[bx][by]!=-1)
				{
					 temp1.i=bx;
                     temp1.j=by;
				     temp1.cost=temp.cost+mg[bx][by];
                   // printf("����е�Ԫ����%d,%d\n",bx,by);
					pre[bx][by].i=temp.i;//bx,by�����ڽ����±�ֵ
					pre[bx][by].j=temp.j;//������¼ǰ�������±�ֵ
					pre[bx][by].num=mg[temp.i][temp.j];
                   // printf("pre[%d][%d]=(%d,%d),������ʵ��(%d,%d)\n",bx,by,temp.i,temp.j,pre[bx][by].i,pre[bx][by].j);
                    
                   // printf("pre[%d][%d]��ǰ����(%d,%d)\n",bx,by,temp.i ,temp.j );//ÿһ������е�������һ��
                     
                    //printf("(%d,%d)->(%d,%d)\n",bx,by,temp.i,temp.j);
					q.push(temp1);//����У�


				    flag[bx][by]=1;//���Ϊ1;�߹���֮��Ͳ��������ˣ�
				/*	for(;;)
					{
						bx1=bx;
						by1=by;
						if(bx==0 && by==0) break;
						printf("(%d,%d)->",bx1,by1);
						bx=pre[bx1][by1].i;
						by=pre[bx1][by1].j;//׷����ô�ã������ҳ�Ԫ���ˣ�
					//������ԭ������䣬1.bx=pre[bx][by]; 2.by=pre[bx][by];ִ�е�һ��ʱ��bx�Ѿ��ı䣬Ҳ����˵ǰһ��pre[bx][by]�ͺ�һ��pre[bx][by]���ܲ�Ϊͬһ����
					//�������ɵɵ�ر����С��������˲��һ�죬������ܵ������Լ���ܸУ�����ģ�̫�ӵ��ˣ��Ժ�һ��Ҫϸ�ģ������Ĵ����ٷ����Σ������˵ģ�
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
	for(x1=m-1,y1=n-1;;)//���յ㿪ʼ��һ��������ǰѹջ
	{
		x2=x1;
	    y2=y1;
	    //cout<<'('<<x1<<','<<y1<<')'<<endl;//���x1��y1��ֵ��Ӧ��˵���ﲻӦ�ó��ִ��󰡣�
	    s.push(pre[x2][y2]);//���ϵ�ѹջ
		x1=pre[x2][y2].i;//���ϵ���ǰ��Ѱǰ���
		y1=pre[x2][y2].j;//һֱѹ����x1=0,y1=0;
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
	char str[SIZE];//�ַ�������
	while(scanf("%d %d",&m,&n)>0)
	{
		 for(i=0;i<m;i++)//m��
		 {
            cin>>str;//�����ַ���
			for(k=0;k<n;k++)//n��
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
		 }//map����仯�ˣ�û�����⣡*/
		 //memset(flag,0,sizeof(flag));//�ؼ�����������ӣ����ύ�˼��ζ�WA����Ȼ����Ϊ�����������
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

