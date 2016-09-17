#include<stdio.h>
#include<string.h>
const int  MAX 65543 
bool flag[MAX] ;
int prime[MAX/2];

//����ɸѡģ�� 
void get_prime( int &k )//�õ�����,k=0 
{
  memset(flag,true,sizeof(flag)) ;//��־Ϊture 
  int i,j;
  for(i=2;i<MAX;i++)
  {
      if(flag[i])
        prime[k++]=i;//prime�������������,k�������� 
        //��i 
      for (j=0;j<k&& i*prime[j]<MAX ;j++ )//������ֱ����������ɸѡ 
      {
          flag[i*prime[j]]=false;
          if (i%prime[j]==0) break;
      }
  }
}

int main ()
{
 int n,k=0;
 get_prime(k);//�����ǵõ����е����� 
 while ( scanf ("%d",&n)!= EOF ) 
 {
       int i ;
       bool first=true;
       for ( i=0; i<k ; i++ )
       {
           while(n%prime[i]==0)//һ�����Ա����� 
           {
                 if (first) 
                 {
                     printf("%d",prime[i]);
                     first=false;
                 }
                 else printf("*%d",prime[i]) ;
                 n /= prime[i]; 
           }
      }
      printf("\n");
 }
       return 0 ; 
}











// ��������ɸѡ�� Ver2 
// ������n ���n����(����n)������
// ����ֵ��n������������ 
int CompositeNumFilterV2(int n)
{
 int i, j;
 // ��������ͳ�� 
 int count = 0;
 // ����������ǿռ䣬����+1ԭ���˰ɣ���Ϊ�˷���һ��flag[0]
 char* flag = (char*)malloc( n+1 ); 
 
 // ��ʼ��������ǣ�Ҫ��Ч�㿩
 flag[2] = 1;
 // ע����i<n���������е�i<=n�ˣ�������˼ 
 for (i=3; i<n; i++)
 {
  flag[i++] = 1;
  // ż����Ȼ����������ֱ����0���� 
  flag[i] = 0;
 }
 // nΪ���� 
 if (n%2 != 0)
 {
  flag[n] = 1;
 }
 
 // ��3��ʼfilter����Ϊ2�ı������ڳ�ʼ��ʱ���͸ɵ���
 // ��n/2ֹ�����ɻ�Ҫ˵�� 
 for (i=3; i <= n/2; i++)
 {
  // i�Ǻ�������Ъ�Űɣ���Ϊ���Ĺ����������������Ӵ����� 
  if (0 == flag[i]) continue;
  
  // ��i��2����ʼ���ˣ���˷�Ϊ�ӷ�  
  for (j=i+i; j <= n; j+=i)
  {
   flag[j] = 0;
  }
 }
 
 // ͳ����������
 for (i=2; i<=n; i++)
 {
  if (flag[i]) count++;
 }
  
 // �������ʱ���Һ��㷨������ز��󣬹���
  
 // �ͷ��ڴ棬�����˴�˵�е��ڴ�й© 
 free(flag);
 
 return count;
} 





