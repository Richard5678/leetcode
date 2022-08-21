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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        ListNode *head = nullptr;
        ListNode *current = nullptr;
        while (true) {
            int minIndex = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != nullptr &&
                      (minIndex < 0 || lists[i]->val < lists[minIndex]->val)) {
                    minIndex = i;
                }
            }
            if (minIndex < 0) {
                break;
            }
            if (head == nullptr) {
                head = lists[minIndex];
                current = head;
            } else {
                current->next = lists[minIndex];
                current = current->next;
            }
            lists[minIndex] = lists[minIndex]->next;
        }
        
        return head;
    }
};