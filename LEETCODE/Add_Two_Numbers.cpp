#include <algorithm>
#include <stdint.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *head = new ListNode(0);
		ListNode *previousPos = head;
		// then begin to add
		int carry = 0;
		ListNode* lr;
		while (l1 && l2) {
			int sum = l1->val + l2->val + carry;
			previousPos->next = new ListNode(sum % 10);
			carry = sum / 10;
			l1 = l1->next;
			l2 = l2->next;
			previousPos = previousPos->next;
		}
		if (!l1) lr = l2;
		else lr = l1;
		while (lr) {
			int sum = lr->val + carry;
			previousPos->next = new ListNode(sum % 10);
			carry = sum / 10;
			lr = lr->next;
			previousPos = previousPos->next;
		}
		if (carry) previousPos->next = new ListNode(carry);
		return head->next;
	}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) { // very beautiful code.
	ListNode preHead(0), *p = &preHead;
	int extra = 0;
	while (l1 || l2 || extra) {
		int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
		extra = sum / 10;
		p->next = new ListNode(sum % 10);
		p = p->next;
		l1 = l1 ? l1->next : l1;
		l2 = l2 ? l2->next : l2;
	}
	return preHead.next;
}

void testCaseOne() {
	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	Solution s;
	ListNode *head = s.addTwoNumbers(l1, l2);
	cout << head->val << " " << head->next->val << " " << head->next->next->val << endl;
}

void printListNode(ListNode *l1) {
	while (l1) {
		cout << l1->val << " ";
		l1 = l1->next;
	}
}

void addTail(ListNode* l, int val) {
	ListNode *previousNode = l;
	while (l) {
		previousNode = l;
		l = l->next;
	}
	previousNode->next = new ListNode(val);
}

int main() {
	ListNode *l1 = new ListNode(1);
	addTail(l1, 9);
	addTail(l1, 9);
	addTail(l1, 9);
	addTail(l1, 9);
	addTail(l1, 9);
	addTail(l1, 9);
	addTail(l1, 9);
	addTail(l1, 9);
	addTail(l1, 9);
	addTail(l1, 9);
	addTail(l1, 9);
	addTail(l1, 9);
	addTail(l1, 9);

	ListNode *l2 = new ListNode(9);

	Solution s;
	ListNode *head = s.addTwoNumbers(l2, l1);

	printListNode(head);
	system("pause");
}