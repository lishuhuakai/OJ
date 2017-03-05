#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		// sort(nums.begin(), nums.end());
		// 事实上,我们并不能断定跟定的nums是否是有序的
		// 排序之后,开始遍历
		unordered_map<int, int> hash;
		vector<int> result;
		for (int i = 0; i < nums.size(); ++i) {
			int numberToFind = target - nums[i];
			if (hash.find(numberToFind) != hash.end()) {
				result.push_back(i);
				result.push_back(hash[numberToFind]);
				return result;
			}
			
			//hash.insert(make_pair(nums[i], i));
			//hash.insert({ nums[i], i });
			hash.insert({ {nums[i], i} });
		}	
		return result;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 2, 7, 11, 15 };
	auto res = s.twoSum(nums, 9);
	for (auto i : res) {
		cout << i << endl;
	}
	system("pause");
}
