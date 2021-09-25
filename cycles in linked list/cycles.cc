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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode *ptr1 = head;
        ListNode *ptr2 = head;
        
        // traverse (length of at least 2)
        while (ptr1 != NULL && ptr2 != NULL && ptr2->next != NULL) {
            ptr2 = ptr2->next->next;
            ptr1 = ptr1->next;
            // if a loop exists
            if (ptr1 == ptr2) {
                return true;
            }
        }
        
        // when break was triggered in the previous loop
        
        return false;
    }
};