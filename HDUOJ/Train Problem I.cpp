/*
�������һ����ջ��ջģ�⺯��,Ҫ������ʹ��ģ�棬
��ô���������ͺܷ����ˣ�
 1. v.push_back(t)    ��������������һ��ֵΪt�����ݣ�������size���
����list��push_front()��������ǰ�˲��룬�����Ԫ���±���������

 2. v.size()      �������������ݵĸ�����size������Ӧvector�ඨ���size_type��ֵ��v.resize(2*v.size)�� 
 v.resize(2*v.size, 99) ��v����������(������Ԫ�ص�ֵ��ʼ��Ϊ99)

 3. v.empty()     �ж�vector�Ƿ�Ϊ��

 4. v[n]           ����v��λ��Ϊn��Ԫ�� 

 5. v.insert(pointer,number, content)  ��v��pointerָ���λ�ò���number��content�����ݡ�
 
 ����v. insert(pointer, content)��v.insert(pointer,a[2],a[4])��a[2]��a[4]����Ԫ�ز��롣

 6. v.pop_back()    ɾ��������ĩԪ�أ��������ظ�Ԫ�ء�

 7.v.erase(pointer1,pointer2) ɾ��pointer1��pointer2�м䣨����pointer1��ָ����Ԫ�ء�
 vector��ɾ��һ��Ԫ�غ󣬴�λ���Ժ��Ԫ�ض���Ҫ��ǰ�ƶ�һ��λ�ã���Ȼ��ǰ������λ��û���Զ���1�� 
 �������ں���Ԫ�ص�˳��ǰ�ƣ�Ҳ���൱�ڵ��������Զ�ָ����һ��λ��һ����

 8. v1==v2          �ж�v1��v2�Ƿ���ȡ�

 9. ��=��<��<=��>��>=      ������Щ���������к��塣
 
 10. vector<typeName>::iterator p=v1.begin( ); p��ʼֵָ��v1�ĵ�һ��Ԫ�ء�*pȡ��ָ��Ԫ�ص�ֵ��
 
 ����const vector<typeName>ֻ����vector<typeName>::const_iterator���͵�ָ����ʡ�

 11.   p=v1.end( ); pָ��v1�����һ��Ԫ�ص���һλ�á�
 
 12.v.clear()      ɾ�������е�����Ԫ�ء�
*/


//�������ڳ�ʱ������Ҫ�Ż����룡
#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int num,i,k;
	string in,out;
	while(scanf("%d",&num)!=EOF)
	{
		i=0;k=0;
		cin>>in>>out;
		stack<char> s;//����һ��ջ
		vector<string> pr;//����string���͵����� 
		while(i<num)//һ��Ҫ��n��Ԫ�ؽ�ջ��
		{
           
           
			s.push(in[i]);//ѹջ
			i++;
            pr.push_back("in");//��β������һ�����ݣ�
			while(!s.empty())//ջ��Ϊ��ʱѭ��
//���ܻ�������������ջ��ͬʱջ������ˣ���Ȼ�����ٳ�ջ��
			{
				if(s.top()==out[k])//ջ��Ԫ�ص��ڳ�ջ���е�Ԫ��
				{
					s.pop();//��ջ
					k++;
                    pr.push_back("out");//��β������һ������
				}
				else break;
			}
			
		}
		if(!s.empty())//ջ��Ϊ��
		cout<<"No."<<endl;
		else
		{
			cout<<"Yes."<<endl;
			for (i=0;i<pr.size();i++)//pr.size(),����������ʵ�����ݵĸ�����
			cout<<pr[i]<<endl;
		}
       cout<<"FINISH"<<endl;
	 // pr.clear();//c.clear()�Ƴ���������������!
	  //for (i=0;i<s.size();i++)
	  //s.pop();//��ջ����գ�
	}
	return 0;
}
