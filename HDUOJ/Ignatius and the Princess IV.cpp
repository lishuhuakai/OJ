//Ignatius and the Princess IV
#include<iostream>
using namespace std;
const int MAX=10000;
int count[MAX];
int main()
{
    int num,cases;
    int i,s;
    while(cin>>num && num>0)
    {
      memset(count,0,sizeof(count));
	 // for(i=0;i<100;i++)
	//	  cout<<count[i]<<endl;
      for(i=0;i<num;i++)
      {
         cin>>cases;
         count[cases]++;               
      }
      s=(num+1)/2;
      for(i=0;i<MAX;i++)
      if(count[i]>=s)
      {
          cout<<i<<endl;
          break;
      }  
                 
    }
    return 0;
}
