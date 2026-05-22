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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* cur = &dummy;
        while(cur != nullptr){
            if(cur->next != nullptr && cur->next->val == val){
                ListNode* del= cur->next;
                cur->next = del->next;
                delete(del);
            }
            else {
                cur = cur->next;
            }
        }

        return dummy.next;
    }
};