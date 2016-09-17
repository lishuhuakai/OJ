#include<iostream>
using namespace std;
int main()
{
    float num,sum;
    sum=0;
    for(int i=1;i<=12;i++)
    {
    cin>>num;
    sum=sum+num;
    }
    cout<<"$"<<sum/12<<endl;
    system("pause");
    return 0; 
}
