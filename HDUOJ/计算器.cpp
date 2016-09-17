//该程序只可以实现一位数字的‘+’ ‘-’ ‘*’ ‘/’运算！
#include<iostream>
#include<cstdio>
#include<string.h>
#include<stack>

using namespace std;
//居然说是数组越界！没有啊！
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
			if(str[i]==' ') i++;//如果读到的是空格，就继续读
		
			else   if(Isnum(str[i]))//如果读到的是数字！
					{
					   s=str[i]-'0'; i++;
					   while(str[i]!=' '&& str[i]!='\0')//是数字就压栈！
					   {
						 s=s*10+(str[i]-'0');
						 i++;
					   }
					   s2.push(s);
					}
					else//如果是操作符！
					if(s1.empty()) {s1.push(str[i]);i++;}
					else//不是空栈
					{   
						flag=1;
						while(flag)//那么就与栈顶元素比较,一直到将ch插入栈中为止!
						{
							if(Compare(str[i],s1.top())==1)
							{
							   s1.push(str[i]); flag=0;//优先级大，则入栈
							}
							else
							{
								theta=s1.top(); s1.pop();//否则出栈
								b=s2.top(); s2.pop();
								a=s2.top(); s2.pop();
								s2.push(Caculate(a,theta,b));//将计算的值压入到数字栈中去！
							}
						}
						i++;
					}
		}//for循环！
		*/
          for(i=0;i<strlen(str);)//按照这段程序来运行的时候，又是对的！
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


       /*for(i=0;i<strlen(str);)//按照这段程序来运行的时候，又是对的！
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
					else//不是空栈
					{   
						flag=1;
						while(flag)//那么就与栈顶元素比较,一直到将ch插入栈中为止!
						{
                            
							if(Compare(str[i],s1.top())==1)
							{
							   s1.push(str[i]); flag=0;//优先级大，则入栈
							}
							else
							if(!s1.empty())
							{
								theta=s1.top(); s1.pop();//否则出栈
								b=s2.top(); s2.pop();
								a=s2.top(); s2.pop();
								s2.push(Caculate(a,theta,b));//将计算的值压入到数字栈中去！
								
							}
							else//表明s1空了
							{ s1.push(str[i]); flag=0;}//这里还有一种情况！如果s1一直出栈！那么s1可能会变成空栈
				            //那样的话！一旦遇到这种情况！那么，将str[i]入栈，并且不再比较！
						}
						i++;
					}
				 }//switch
			}//else
			*/
			while(!s1.empty())//读完后，一旦字符栈不为空，那么就要出栈！
			{
				theta=s1.top(); s1.pop();
				b=s2.top(); s2.pop();
				a=s2.top(); s2.pop();
				s2.push(Caculate(a,theta,b));
			}
			s=s2.top();
			s2.pop();
			printf("%.2lf\n",s);//应该说，代码没有多大的问题啊！
	}
	return 0;
}