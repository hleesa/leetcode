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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int minLen = nodeLength(headA);
        int maxLen = nodeLength(headB);
        if(minLen > maxLen){
            swap(minLen, maxLen);
            swap(headA, headB);
        }
        for(int i = 0; i < maxLen - minLen; ++i){
            headB = headB->next;
        }

        for(int i = 0; i < minLen; ++i){
            if(headA == headB) break;
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }

private:
    int nodeLength(ListNode* head){
        int len = 0;
        while(head != nullptr){
            ++len;
            head = head->next;
        }

        return len;
    }
};