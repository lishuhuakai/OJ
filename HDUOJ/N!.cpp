//首先需要肯定，程序是正确的 
//这算是大数乘除法！记住他们是如何处理的！由于数据很大，用基本数据类型根本无法满足要求，只能用数组来表示！
//大数乘法！10000！的阶乘是在太大！几次数组开小了都报错误！
#include <iostream>
#include<cstdio>
#include<memory.h>
using namespace std;
#define MAX 10000
#define BASE 100000//base只是一个基度，对最终取值并没有影响，相反，base取值愈大，计算量愈小
//base发生改变的时候，下面的输出也要相应地做出调整，否则也会输出错误答案！除非当base取10！
int h[MAX];
//这是我第二次接触大数的乘法！现在复习一下吧！很好的算法！

int main()
{
    int i,j,k,carry;
	int n;
    
	while(scanf("%d",&n)!=EOF)
	{  
		memset(h,0,MAX*sizeof(int));//赋值，每一个都置为0 
		for(i=1,h[MAX-1]=1;i<=n;++i)//运用递归，并且h[1]=1; 
		for(k=MAX-1,carry=0;k>=0;--k)//从最后一位开始相乘,依次向前与每一位相乘 
		{ 
			carry+=i*h[k];
			h[k]=carry%BASE;
			carry/=BASE;//carry表示进位
		}       
		for(j=0;j<MAX && h[j]==0;++j);//从0位开始搜索，找到不为0的第一个数 
		printf("%d",h[j++]);//像是这个输出，就很妙了，第一位可能不足四位，就地输出！
        for(;j<MAX;++j)
		printf("%05d",h[j]);//处在中间的值也可能没有五位，这时候要注意了，往左边加0，凑足5位，不然答案会出错！	
    	printf("\n");
	}
    //system("pause");
	
    return 0;
}
