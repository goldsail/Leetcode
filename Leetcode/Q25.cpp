
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution 
{
	ListNode *fun(ListNode *node, int k)
	{
		if (k < 2)
			return node;
		ListNode *start = node;
		ListNode *curr = node;
		ListNode *temp = nullptr;
		ListNode *tmp = nullptr;
		ListNode *end = nullptr;
		int count = 0;
		while (curr && count < k)
		{
			curr = curr->next;
			count++;
		}
		if (count < k)
		{
			return start;
		}
		else
		{
			end = curr;
			curr = start;
			temp = curr->next;
			int count2 = 1;
			while (count2 < k)
			{
				count2++;
				tmp = temp->next;
				temp->next = curr;
				curr = temp;
				temp = tmp;
			}
			start->next = fun(end, k);
			return curr;
		}
	}

public:
	ListNode* reverseKGroup(ListNode* head, int k) 
	{
		return fun(head, k);
	}
};