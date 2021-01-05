/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        head = new ListNode(0, head); // dummy head node
        sums = unordered_map<int, ListNode*>();
        cache = unordered_map<ListNode*, int>();
        
        ListNode* curr = head;
        int sum = 0;
        while (curr) {
            sum += curr->val;
            cache[curr] = sum;
            //
            if (sums[sum] == nullptr) {
                sums[sum] = curr;
            } else {
                // delete nodes in between
                ListNode *prev = sums[sum];
                while (prev->next != curr->next) {
                    ListNode *temp = prev->next;
                    prev->next = temp->next;
                    sums[cache[temp]] = nullptr;
                }
                sums[sum] = prev;
            }
            curr = curr->next;
        }
        //
        return head->next;
    }
    
private:
    unordered_map<int, ListNode*> sums;
    unordered_map<ListNode*, int> cache;
};
