struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		
		ListNode *curr1 = l1;
		ListNode *curr2 = l2;
		ListNode *curr3 = new ListNode(0);
		ListNode *start = curr3;
		int carry = 0;
		while (curr1 || curr2)
		{
			int x1 = curr1 ? curr1->val : 0;
			int x2 = curr2 ? curr2->val : 0;
			ListNode *temp = new ListNode((x1 + x2 + carry) % 10);
			carry = (x1 + x2 + carry) / 10;
			curr3->next = temp;
			curr3 = temp;
			curr1 = curr1 ? curr1->next : curr1;
			curr2 = curr2 ? curr2->next : curr2;
		}
		if (carry > 0)
		{
			curr3->next = new ListNode(carry);
		}
		return start->next ? start->next : start;
	}
};