//�ó���ֻ����ʵ��һλ���ֵġ�+�� ��-�� ��*�� ��/�����㣡
#include<iostream>
#include<cstdio>
#include<string.h>
#include<stack>

using namespace std;
//��Ȼ˵������Խ�磡û�а���
int cmp[4][4]={
	1,1,0,0,
	1,1,0,0,
	1,1,1,1,
	1,1,1,1};

bool Isnum(char ch)
{
	if(ch >= '0' && ch <= '9') return true;
	else return false;
}

double Caculate(double a,char b,double c)
{
	switch(b)
    {
		case '+':return a+c;
		case '-':return a-c;
		case '*':return a*c;
		case '/':return a/c;
	}
	return 0;
}

inline int Compare(char &a,char &b)
{
	int m,n;
	switch(a)
   {    
	    case '+':m=0;break;
		case '-':m=1;break;
		case '*':m=2;break;
		case '/':m=3;break;
	}
	switch(b)
    {    
	    case '+':n=0;break;
		case '-':n=1;break;
		case '*':n=2;break;
		case '/':n=3;break;
	}
	return cmp[m][n];
}

int main()
{
	char str[300];
	double a,b;
	char theta;
	int i,flag;
	double s;
	

    while(gets(str))
	{
		if(strcmp("0",str)==0) break;
		stack<char> s1;
	    stack<double> s2;
		
        /*
		for(i=0;i<strlen(str);)
		  { 
		   switch(str[i])
		   {
		   case '0':
		   case '1':
		   case '2':
		   case '3':
		   case '4':
		   case '5':
		   case '6':
		   case '7':
		   case '8':
		   case '9':
			     s=str[i]-'0'; i++;
				 while(str[i]!=' '&& str[i]!='\0')
				 {
				   s=s*10+(str[i]-'0');
				   i++;
				 }
			     s2.push(s);
			     i++;  break;
		   //cout<<sum<<endl;
			  
		   case '+':
		   case '-':
			   if(s1.empty())
				 s1.push(str[i]);
			   else
			   {
					while(!s1.empty())
					{
					 theta=s1.top();s1.pop();
					 b=s2.top();s2.pop();
					 a=s2.top();s2.pop();
					 s2.push(Caculate(a,theta,b));
					}
					s1.push(str[i]);
			   }
			   i+=2; break;
			  
		  case '/':
		  case '*':
				 if(s1.empty())
			     s1.push(str[i]);
				 else
				 {
					  if(s1.top()=='*'||s1.top()=='/')
					  {
						  theta=s1.top();s1.pop();
						  b=s2.top();s2.pop();
						  a=s2.top();s2.pop();
						  s2.push(Caculate(a,theta,b));
					  }
					  s1.push(str[i]);
				 }
				 i+=2; break;
				 
		   }
		  }*/
		
		 /*
		 for(i=0;i<strlen(str);)
		 {
			if(str[i]==' ') i++;//����������ǿո񣬾ͼ�����
		
			else   if(Isnum(str[i]))//��������������֣�
					{
					   s=str[i]-'0'; i++;
					   while(str[i]!=' '&& str[i]!='\0')//�����־�ѹջ��
					   {
						 s=s*10+(str[i]-'0');
						 i++;
					   }
					   s2.push(s);
					}
					else//����ǲ�������
					if(s1.empty()) {s1.push(str[i]);i++;}
					else//���ǿ�ջ
					{   
						flag=1;
						while(flag)//��ô����ջ��Ԫ�رȽ�,һֱ����ch����ջ��Ϊֹ!
						{
							if(Compare(str[i],s1.top())==1)
							{
							   s1.push(str[i]); flag=0;//���ȼ�������ջ
							}
							else
							{
								theta=s1.top(); s1.pop();//�����ջ
								b=s2.top(); s2.pop();
								a=s2.top(); s2.pop();
								s2.push(Caculate(a,theta,b));//�������ֵѹ�뵽����ջ��ȥ��
							}
						}
						i++;
					}
		}//forѭ����
		*/
          for(i=0;i<strlen(str);)//������γ��������е�ʱ�����ǶԵģ�
		  { 
		       if(str[i]==' ') i++;
			   else
		       if(Isnum(str[i]))
			   {
					 s=str[i]-'0'; i++;
					 while(str[i]!=' '&&str[i]!='\0')
					 {
					   s=s*10+(str[i]-'0');
					   i++;
					 }
					 s2.push(s);
					 i++; 
			   }
			  else
			  {
				 switch(str[i])
				 {
				   case '+':
				   case '-':
					   if(s1.empty())
						 s1.push(str[i]);
					   else
					   {
							while(!s1.empty())
							{
							 theta=s1.top();s1.pop();
							 b=s2.top();s2.pop();
							 a=s2.top();s2.pop();
							 s2.push(Caculate(a,theta,b));
							}
							s1.push(str[i]);
					   }
					   i+=2; break;
					  
				  case '/':
				  case '*':
						 if(s1.empty())
						 s1.push(str[i]);
						 else
						 {
							  if(s1.top()=='*'||s1.top()=='/')
							  {
								  theta=s1.top();s1.pop();
								  b=s2.top();s2.pop();
								  a=s2.top();s2.pop();
								  s2.push(Caculate(a,theta,b));
							  }
							  s1.push(str[i]);
						 }
						 i+=2; break;
				 }//switch
			}//else
				 
	 }//for


       /*for(i=0;i<strlen(str);)//������γ��������е�ʱ�����ǶԵģ�
		  { 
		       if(str[i]==' ') i++;
			   else
		       if(Isnum(str[i]))
			   {
					 s=str[i]-'0'; i++;
					 while(str[i]!=' '&& str[i]!='\0')
					 {
					   s=s*10+(str[i]-'0');
					   i++;
					 }
					 s2.push(s);
					 //i--; 
			   }
			  else
			  {
				 if(s1.empty()) {s1.push(str[i]);i++;}
					else//���ǿ�ջ
					{   
						flag=1;
						while(flag)//��ô����ջ��Ԫ�رȽ�,һֱ����ch����ջ��Ϊֹ!
						{
                            
							if(Compare(str[i],s1.top())==1)
							{
							   s1.push(str[i]); flag=0;//���ȼ�������ջ
							}
							else
							if(!s1.empty())
							{
								theta=s1.top(); s1.pop();//�����ջ
								b=s2.top(); s2.pop();
								a=s2.top(); s2.pop();
								s2.push(Caculate(a,theta,b));//�������ֵѹ�뵽����ջ��ȥ��
								
							}
							else//����s1����
							{ s1.push(str[i]); flag=0;}//���ﻹ��һ����������s1һֱ��ջ����ôs1���ܻ��ɿ�ջ
				            //�����Ļ���һ�����������������ô����str[i]��ջ�����Ҳ��ٱȽϣ�
						}
						i++;
					}
				 }//switch
			}//else
			*/
			while(!s1.empty())//�����һ���ַ�ջ��Ϊ�գ���ô��Ҫ��ջ��
			{
				theta=s1.top(); s1.pop();
				b=s2.top(); s2.pop();
				a=s2.top(); s2.pop();
				s2.push(Caculate(a,theta,b));
			}
			s=s2.top();
			s2.pop();
			printf("%.2lf\n",s);//Ӧ��˵������û�ж������Ⱑ��
	}
	return 0;
}