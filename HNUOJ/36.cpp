#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int SIZE = 110;
bool mark[SIZE * SIZE];
int sum[SIZE * SIZE];
int num[SIZE];
/* 总体来说，这道题目意义不大！ */

/**
 * 设所求的n个数按从小到大排列为a1,a2....an。
 * a1 + a2 一定是 n * (n - 1) / 2 个数的序列中最小的，a1 + a3 一定是次小的，通过枚举 a2 + a3 的值解出符合条件的a1,a2,a3,
 * 把他们两两相加的结果从 n * (n - 1) / 2 个数中排除，然后 n * (n - 1) / 2 个数中剩下的第一个没有被排除的数一定是a1 + a4的值，
 * 这样可以求的a4，然后再从n * (n - 1) / 2个数中除去a1 + a4，a2 + a4，a3 + a4，然后 n * (n - 1) / 2 个数中剩下的第一个没有被排除
 * 的数一定是a1 + a5的值，这样可以求的a5，如此重复，直到求的an的值，并除去a1 + an, a2 + an,....an-1 + an，此时如果n * (n - 1) / 2
 * 个数已经全部除去，那么就得到了答案，否则，说明枚举的a2 + a3的值仍不合要求，继续枚举下一个a2+a3的值。
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
			// 枚举求出num[1], num[2], num[3];
			// num[1] + num[2]一定为 sum[1];
			// num[1] + num[3]一定为 sum[2];
			// 而num[2] + num[3]的值不确定，因此枚举i(3,m);
			num[2] = (sum[1] - sum[2] + sum[i]) / 2; // 确实，从这里开始就是枚举了，sum[1] - sum[2] = num[2] - num[3]
			/* 而我们现在要寻找num[2] + num[3],这个值可能是sum[i], i从3取到m中任何一个，究竟是哪一个，我们不知道，所以枚举 */
			num[1] = sum[1] - num[2];
			num[3] = sum[2] - num[1];
			/* 假设num[2] + num[3] = sum[i],这样的话，按照前面的步骤可以计算出num[1], num[2], num[3],反过来也可以验证 */
			if (num[2] + num[3] != sum[i]) continue;

			memset(mark, false, sizeof(mark)); /* 全部标记为false */
			mark[1] = true; /* num[1] + num[2]可以推出sum[1] */
			mark[2] = true; /* num[1] + num[3]可以推出sum[2] */
			mark[i] = true; /* num[2] + num[3]可以推出sum[i] */
			/** 可以看见，我们将num[1], num[2], num[3]的各种可能的组合加起来的sum都标记了，所以mark中下一个未被标记的元素mark[j]对应的sum[j]一定是
			 * num[1] + num[4]的值，因为它们加起来的值是未被标记的sum中的元素中最小的。所以可以推导出num[4]
			 */
			int k = 3; /* 接下来判断sum[i], i从3到m是否可以从已知的条件中推出，可以的话，将mark[i]标记为true */
			bool flag = true; 
			for (int j = 4; j <= n && flag; j++) {
				while (mark[k]) // 从第3个元素开始，搜寻mark数组中第一个不为true的元素,也是sum[i]中暂时未被推导出的最小的一个元素
					k++;
				num[j] = sum[k] - num[1]; 
				mark[k] = true; /* num[1] + num[j] */
				// 去掉num[2] + num[j], num[3] + num[j], num[4] + num[j].... num[j-1] + num[j];
				// 需要注意的是，num[2] + num[j], num[3] + num[j], num[4] + num[j].... num[j-1] + num[j];
				// 它们的大小是从小排到大的。
				// 那么剩下的第一个没有被排除的数一定是num[1] + num[j+1](此时是下一个循环）
				for (int l = 2; l < j && flag; l++) {
					// 排除num[j] + num[l] (2 <= l <= j-1)
					// 这个玩意的解释有点复杂，真的很复杂。
					for (int x = k + 1; x <= m; x++) {
						flag = false;
						if (!mark[x] && num[l] + num[j] == sum[x]) {
							mark[x] = true; /* 如果么有被标记，则标记一下，表示这个玩意已经被我们可以推断出来了 */
							flag = true;
							break;
						}
					}
				}
			}
			if (flag) 
				break;//说明此时已经生出n个数
		}

		for (int i = 1;  i < n; i++) 
		{
			cout << num[i] << " ";
		}
		cout << num[n] << endl;
	}
	return 0;
}
