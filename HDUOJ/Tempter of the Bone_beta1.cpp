//����������Թ��㷨�������ķ��ˣ�
/********************************************
di��ָ�ķ�λ��
0 �ϣ�
1 �ң�
2 �£�
3 ��
********************************************/
#include<iostream>
using namespace std;
const int MAX=100;//maxҪ����㣬��Ȼ����ACCESS_VIOLATION�Ƿ����ʣ���ָ��Խ�磡��
const int SIZE=8;

typedef struct
{
	int i;//��ǰ������к�
	int j;//��ǰ������к�
	int di;//di��¼��һ���߷�λ�ķ�λ��
}Stack;//ջ����

Stack st[MAX];

int mg[SIZE][SIZE];
int length[MAX];

int mgpath(int x1,int y1,int x2,int y2)//����յ������ֵ
{
  int i,j,di,find,k=-1;
  int top=-1;//��ʼ��ջָ��
  top++;
  st[top].i=x1; st[top].j=y1; st[top].di=-1; mg[x1][y1]=-1;//��ʼ���������ջ
  while(top>-1)//ջ��Ϊ��ʱѭ��
  {
	  i=st[top].i; j=st[top].j; 
	  di=st[top].di;//����һ�ʣ���¼�¸÷������һ�����߷�λ������diֻ����������С��4�����Ա�֤���������߹���·
	  if(i==x2 && j==y2)//�ҵ����յ�
	  {
		  k++;
		  length[k]=top;//��¼������·���ĳ���
		  mg[x2][y2]=2;
		  top--;//��ջ������Ѱ����һ��·��
          i=st[top].i; j=st[top].j; di=st[top].di;
	  }
	  find=0;
	  while(di<4 && find==0)//�㷨����ĵط�
	  {
		  di++;//�ȼӼӣ�ָ����һ������!
		  switch(di)
		  {
			  case 0: i=st[top].i-1; j=st[top].j; break;
			  case 1: i=st[top].i; j=st[top].j+1; break;
			  case 2: i=st[top].i+1; j=st[top].j; break;
			  case 3: i=st[top].i; j=st[top].j-1; break;
		  }
		  if(mg[i][j]==2) find=1;//����Խ�磡mg�����г����Ѿ��õ��ģ������ֵ��Ϊ0��
	  }
	  if(find==1)//�ҵ�����һ�����߷���
	  {
		  st[top].di=di;//�޸�ԭջ��Ԫ�ص�diֵ
		  top++;//��һ�����߷����ջ
		  st[top].i=i; st[top].j=j; st[top].di=-1;
		  mg[i][j]=-1;//�߹��ķ�����Ϊ-1�������ظ��ߵ��÷���
	  }
	  else//û��·�����ߣ�����ջ
	  {
		  mg[st[top].i][st[top].j]=2;//�ø�λ�ñ�Ϊ����·�����߷���
		  top--;
	  }
  }
  return k+1;
}

int main()
{
	int m,n,time;
	int i,j,k;
	char str[SIZE];//�ַ�������
	int a,b,c,d;//��¼����յ��ֵ
	while(cin>>m>>n>>time && (m!=0 && n!=0 && time!=0))
	{
	//	cout<<"m="<<m<<"  "<<"n="<<n<<"   "<<"time="<<time<<endl;
		 for(i=0;i<m;i++)//m��
		 {
            cin>>str;//�����ַ���
			for(k=0;k<n;k++)//n��
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

