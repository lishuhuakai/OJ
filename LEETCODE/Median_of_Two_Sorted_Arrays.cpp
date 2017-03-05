#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int l1 = nums1.size(), l2 = nums2.size();
		int length = l1 + l2;
		bool two_part = ((length % 2) == 0);
		// 然后遍历两个数组即可
		int max_int = 99999999;
		int idx1 = 0, idx2 = 0;
		int m1, m2;
		if (two_part) {
			idx1 = length / 2 - 1;
			idx2 = idx1 + 1;
		}
		else idx1 = idx2 = length / 2;
			
		auto i1 = nums1.begin(), i2 = nums2.begin();
		int idx = 0;
		while (true) {
			int s;
			int n1 = (i1 != nums1.end() ? *i1 : max_int);
			int n2 = (i2 != nums2.end() ? *i2 : max_int);
			if (n1 > n2) {
				i2 = (i2 == nums2.end() ? i2 : ++i2);
				s = n2;
			}
			else {
				i1 = (i1 == nums1.end() ? i1 : ++i1);
				s = n1;
			}
				

			if (idx == idx1) m1 = s;
			if (idx == idx2) {
				m2 = s;
				break;
			}
			idx++;
		}
		return double(m1 + m2) / 2;
	}
};

int main() {
	vector<int> m1 = { 1, 2 };
	vector<int> m2 = { 3, 4 };
	Solution so;
	cout << so.findMedianSortedArrays(m1, m2);
	getchar();
}