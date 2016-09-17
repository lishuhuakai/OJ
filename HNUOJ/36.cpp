#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int SIZE = 110;
bool mark[SIZE * SIZE];
int sum[SIZE * SIZE];
int num[SIZE];
/* ������˵�������Ŀ���岻�� */

/**
 * �������n��������С��������Ϊa1,a2....an��
 * a1 + a2 һ���� n * (n - 1) / 2 ��������������С�ģ�a1 + a3 һ���Ǵ�С�ģ�ͨ��ö�� a2 + a3 ��ֵ�������������a1,a2,a3,
 * ������������ӵĽ���� n * (n - 1) / 2 �������ų���Ȼ�� n * (n - 1) / 2 ������ʣ�µĵ�һ��û�б��ų�����һ����a1 + a4��ֵ��
 * �����������a4��Ȼ���ٴ�n * (n - 1) / 2�����г�ȥa1 + a4��a2 + a4��a3 + a4��Ȼ�� n * (n - 1) / 2 ������ʣ�µĵ�һ��û�б��ų�
 * ����һ����a1 + a5��ֵ�������������a5������ظ���ֱ�����an��ֵ������ȥa1 + an, a2 + an,....an-1 + an����ʱ���n * (n - 1) / 2
 * �����Ѿ�ȫ����ȥ����ô�͵õ��˴𰸣�����˵��ö�ٵ�a2 + a3��ֵ�Բ���Ҫ�󣬼���ö����һ��a2+a3��ֵ��
 */

int main() 
{
	int n;
	while ((cin >> n) && (n != 0)) 
	{
		int m = n * (n - 1) / 2;
		memset(sum, 0, sizeof(sum));
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= m; i++)
			cin >> sum[i];

		sort(sum + 1, sum + m + 1);

		for (int i = 3; i <= m; i++) 
		{
			// ö�����num[1], num[2], num[3];
			// num[1] + num[2]һ��Ϊ sum[1];
			// num[1] + num[3]һ��Ϊ sum[2];
			// ��num[2] + num[3]��ֵ��ȷ�������ö��i(3,m);
			num[2] = (sum[1] - sum[2] + sum[i]) / 2; // ȷʵ�������￪ʼ����ö���ˣ�sum[1] - sum[2] = num[2] - num[3]
			/* ����������ҪѰ��num[2] + num[3],���ֵ������sum[i], i��3ȡ��m���κ�һ������������һ�������ǲ�֪��������ö�� */
			num[1] = sum[1] - num[2];
			num[3] = sum[2] - num[1];
			/* ����num[2] + num[3] = sum[i],�����Ļ�������ǰ��Ĳ�����Լ����num[1], num[2], num[3],������Ҳ������֤ */
			if (num[2] + num[3] != sum[i]) continue;

			memset(mark, false, sizeof(mark)); /* ȫ�����Ϊfalse */
			mark[1] = true; /* num[1] + num[2]�����Ƴ�sum[1] */
			mark[2] = true; /* num[1] + num[3]�����Ƴ�sum[2] */
			mark[i] = true; /* num[2] + num[3]�����Ƴ�sum[i] */
			/** ���Կ��������ǽ�num[1], num[2], num[3]�ĸ��ֿ��ܵ���ϼ�������sum������ˣ�����mark����һ��δ����ǵ�Ԫ��mark[j]��Ӧ��sum[j]һ����
			 * num[1] + num[4]��ֵ����Ϊ���Ǽ�������ֵ��δ����ǵ�sum�е�Ԫ������С�ġ����Կ����Ƶ���num[4]
			 */
			int k = 3; /* �������ж�sum[i], i��3��m�Ƿ���Դ���֪���������Ƴ������ԵĻ�����mark[i]���Ϊtrue */
			bool flag = true; 
			for (int j = 4; j <= n && flag; j++) {
				while (mark[k]) // �ӵ�3��Ԫ�ؿ�ʼ����Ѱmark�����е�һ����Ϊtrue��Ԫ��,Ҳ��sum[i]����ʱδ���Ƶ�������С��һ��Ԫ��
					k++;
				num[j] = sum[k] - num[1]; 
				mark[k] = true; /* num[1] + num[j] */
				// ȥ��num[2] + num[j], num[3] + num[j], num[4] + num[j].... num[j-1] + num[j];
				// ��Ҫע����ǣ�num[2] + num[j], num[3] + num[j], num[4] + num[j].... num[j-1] + num[j];
				// ���ǵĴ�С�Ǵ�С�ŵ���ġ�
				// ��ôʣ�µĵ�һ��û�б��ų�����һ����num[1] + num[j+1](��ʱ����һ��ѭ����
				for (int l = 2; l < j && flag; l++) {
					// �ų�num[j] + num[l] (2 <= l <= j-1)
					// �������Ľ����е㸴�ӣ���ĺܸ��ӡ�
					for (int x = k + 1; x <= m; x++) {
						flag = false;
						if (!mark[x] && num[l] + num[j] == sum[x]) {
							mark[x] = true; /* ���ô�б���ǣ�����һ�£���ʾ��������Ѿ������ǿ����ƶϳ����� */
							flag = true;
							break;
						}
					}
				}
			}
			if (flag) 
				break;//˵����ʱ�Ѿ�����n����
		}

		for (int i = 1;  i < n; i++) 
		{
			cout << num[i] << " ";
		}
		cout << num[n] << endl;
	}
	return 0;
}
