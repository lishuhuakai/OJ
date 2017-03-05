#include <algorithm>
#include <unordered_set>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// o(n) is avaliable
		vector<char> subChars;
		int maxSubstringLength = 0;
		for (auto c : s) {
			//unordered_set<char>::iterator 
			auto it = find(subChars.begin(), subChars.end(), c);
			if (it != subChars.end()) {
				subChars.erase(subChars.begin(), ++it);
			}

			subChars.push_back(c);

			if (maxSubstringLength < subChars.size())
				maxSubstringLength = subChars.size();
		}
		return maxSubstringLength;
	}
};

/**
* Solution (DP, O(n)):
*
* Assume L[i] = s[m...i], denotes the longest substring without repeating
* characters that ends up at s[i], and we keep a hashmap for every
* characters between m ... i, while storing <character, index> in the
* hashmap.
* We know that each character will appear only once.
* Then to find s[i+1]:
* 1) if s[i+1] does not appear in hashmap
*    we can just add s[i+1] to hash map. and L[i+1] = s[m...i+1]
* 2) if s[i+1] exists in hashmap, and the hashmap value (the index) is k
*    let m = max(m, k), then L[i+1] = s[m...i+1], we also need to update
*    entry in hashmap to mark the latest occurency of s[i+1].
*
* Since we scan the string for only once, and the 'm' will also move from
* beginning to end for at most once. Overall complexity is O(n).
*
* If characters are all in ASCII, we could use array to mimic hashmap.
*/

int lengthOfLongestSubstring(string s) {
	// for ASCII char sequence, use this as a hashmap
	vector<int> charIndex(256, -1);
	int longest = 0, m = 0;

	for (int i = 0; i < s.length(); i++) {
		m = max(charIndex[s[i]] + 1, m);    // automatically takes care of -1 case
		charIndex[s[i]] = i; // 最近的下标
		// i - m + 1 表示加上这个字符,一共有多少个不重复的字符
		longest = max(longest, i - m + 1);
	}

	return longest;
}

int main() {
	vector<string> vars = { "nfpdmpi" };
	Solution so;
	for (auto var : vars) {
		cout << so.lengthOfLongestSubstring(var) << endl;
	}

	unordered_set<char> it;
	it.insert('n');
	it.insert('f');
	it.insert('p');
	it.insert('d');
	it.insert('m');
	for (auto i = it.begin(); i != it.end(); ++i)
		cout << *i << " ";
	cout << endl;
	getchar();
}