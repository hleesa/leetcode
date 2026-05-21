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
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        while(cur != nullptr) {
            ListNode* next = cur->next;
            if(next != nullptr && next->val == val){
                ListNode* del = next;
                cur->next = next->next;
                delete(del);
            }
            else {
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};