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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode temp(0);
        temp.next = head;
        head = &temp;
        //
        ListNode *prev = head;
        int count = 0;
        ListNode *curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (count < n) {
                count++;
            } else {
                prev = prev->next;
            }
            curr = curr->next;
        }
        
        prev->next = prev->next->next;
        return head->next;
    }
};