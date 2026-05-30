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
        stack<ListNode*> nodes;
        ListNode* cur = head;
        while(cur != nullptr){
            nodes.push(cur);
            cur = cur->next;
            nodes.top()->next = nullptr;
        }

        ListNode dummy;
        ListNode* temp;
        temp = &dummy;
        while(!nodes.empty()){
            temp->next = nodes.top();
            nodes.pop();
            temp = temp->next;
        }

        return dummy.next;
    }
};