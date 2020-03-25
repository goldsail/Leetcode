/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *curr = start;
        ListNode *prev;
        for (int i = 0; i < m; i++) {
            prev = curr;
            curr = curr->next;
        }
        ListNode *prev0 = prev;
        ListNode *curr0 = curr;
        for (int i = m; i <= n; i++) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        prev0->next = prev;
        curr0->next = curr;
        return start->next;
    }
};
