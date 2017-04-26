#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode 
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct Node
{
	ListNode *node;
	int index;
	bool operator<(const Node &rhs) const
	{
		return (node->val > rhs.node->val);
	}
};

typedef priority_queue<Node> Heap;

class Solution 
{
private:
	ListNode *head;
	ListNode *curr;
	void _insert(int val)
	{
		ListNode *n = new ListNode(val);
		if (curr)
		{
			curr->next = n;
			curr = n;
		}
		else
		{
			curr = n;
			head = n;
		}
	}

public:
	ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
		int num = lists.size();
		ListNode **list = new ListNode*[num + 1];
		for (int i = 0; i < num; i++)
		{
			list[i] = lists[i];
		}
		head = nullptr;
		curr = nullptr;
		//
		Heap heap;
		vector<Node> v;
		for (int i = 0; i < num; i++)
		{
			if (list[i] != nullptr)
			{
				Node temp;
				temp.node = list[i];
				temp.index = i;
				v.push_back(temp);
				list[i] = temp.node->next;
			}
		}
		heap = Heap(v.begin(), v.end());
		while (!heap.empty())
		{
			Node temp = heap.top();
			heap.pop();
			// cout << temp.node->val << endl;
			_insert(temp.node->val);
			list[temp.index] = temp.node->next;
			if (list[temp.index])
			{
				Node t;
				t.index = temp.index;
				t.node = list[temp.index];
				heap.push(t);
			}
		}
		return head;
	}
};
