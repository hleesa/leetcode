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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = head;

        while(head != nullptr && head->next != nullptr){
            if(head->val == head->next->val){
                ListNode* toDelete = head->next;
                head->next = toDelete->next;
                delete(toDelete);
            }
            else{
                head = head->next;
            }
        }

        return res;
    }
};