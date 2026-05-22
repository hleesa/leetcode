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
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* cur = head;
        while(cur != nullptr){
            stk.push(cur);
            cur = cur->next;
            stk.top()->next = nullptr;
        }

        ListNode dummy;
        ListNode* curr = &dummy;
        while(!stk.empty()){
            curr->next = stk.top();
            stk.pop();
            curr = curr->next;
        }

        return dummy.next;
    }
};