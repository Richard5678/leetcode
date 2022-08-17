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
    ListNode *detectCycle(ListNode *head) {
        // linked list of size 0 or 1
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode *ptr1 = head;
        ListNode *ptr2 = head;
        
        // traverse (length of at least 2)
        while (ptr1 != NULL && ptr2 != NULL && ptr2->next != NULL) {
            ptr2 = ptr2->next->next;
            ptr1 = ptr1->next;
            // if a loop exists
            if (ptr1 == ptr2) {
                ptr1 = ptr1->next;
                int length = 1; // length of the loop
                while (ptr1 != ptr2) {
                    ptr1 = ptr1->next;
                    length++;
                }
                
                // reset both pointers
                ptr1 = head;
                ptr2 = head;
                
                // 
                for (int i = 0; i < length; i++) {
                    ptr1 = ptr1->next;
                }
                
                while (ptr1 != ptr2) {
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                } // ends at the start of the loop
                return ptr1;
            }
        }
        
        // when break was triggered in the previous loop
        if (ptr1 != ptr2) {
            return NULL;
        }
        
        return head;
    }
}