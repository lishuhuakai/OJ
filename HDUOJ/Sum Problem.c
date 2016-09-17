#include<stdio.h>
#include<string.h>
#define max 1001

char s[max];
char buff[max];
void sum(char a[max],char b[max])
{
    int top1,top2,n,l,top;
    top1=0;top2=0;
    n=0;l=0;top=0;
    top1=strlen(a);//求a字符串的长度
    top2=strlen(b);//b字符串的长度
    if(top1>top2)//a的长度大于b
        while(top1>0)
            {
                for(;top2>0/*top2是较短位*/;--top1,--top2,++n)//从第一位加起
                {
                      buff[n]=(a[top1-1]+b[top2-1]-96+l)%10+48;//48是'0'的ASCII码，根据字符串的输入规律，第一位就是最高位，我们要从最低位加起
                      l=(a[top1-1]+b[top2-1]-96+l)/10;//可能有进位
                }
                buff[n]=(a[top1-1]-48+l)%10+48;
                l=(a[top1-1]-48+l)/10;
                n++;top1--;
            }
     else
           {
             while(top2>0)//与之前类似
                        {
                               for(;top1>0;--top1,--top2,++n)
                                {
                                       buff[n]=(a[top1-1]+b[top2-1]-96+l)%10+48;
                                        l=(a[top1-1]+b[top2-1]-96+l)/10;
                                }
                               if(top2>0)
                { buff[n]=(b[top2-1]-48+l)%10+48;
                                     l=(b[top2-1]-48+l)/10;
                  n++;top2--;
                }
                        }
       }
     if(l>0)//依然有进位
           {
        buff[n]=l+48;n++;
	 }
    buff[n]='\0';//最后一位添加“\0”;
    for(;n>0;--n)
    {
        s[top]=buff[n-1];
        top++;
    }
    s[top]='\0';//反过来一位位存入s数组里
}
int main()
{
    char a[max],b[max],n,m;
    scanf("%d",&n);
    m=0;
    if(1<=n<=20)
    {
        while(m<n)
        {
            if(scanf("%s %s",a,b))
             sum(a,b);
             printf("Case %d:\n",m+1);
             printf("%s + %s = %s\n",a,b,s);
             m++;
             if(m<n) printf("\n");
        }
    }
    return 0;
}

