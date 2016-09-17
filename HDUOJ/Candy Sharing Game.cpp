#include<iostream>
using namespace std;
const int SIZE=100;

bool equal(int a[],int n)
{
     int t;
     t=a[0];
     for(int i=0;i<n;i++)
     if(a[i]!=t) return false;
     return true;
     
}
int main()
{
    int num[SIZE],num1[SIZE];
    int n,i,k;
    while(cin>>n)
    {
         if(n==0) break;
         for(i=0;i<n;i++)
         {
           cin>>num[i];
           num1[i]=num[i];              
         } 
         k=0;
         while(1)
         {
             num[0]=num1[n-1]/2+num1[0]/2;
             if(num[0]%2!=0) num[0]++;
             for(i=1;i<n;i++)
             {
                num[i%n]=num1[i-1]/2+num1[i%n]/2;
                if(num[i]%2!=0) num[i]++;             
             }
             for(i=0;i<n;i++)
             num1[i]=num[i];
             k++;
             if(equal(num,n))
             {
              cout<<k<<" "<<num[0]<<endl;
              break;             
             }
         }
    }
                
    return 0;
}
