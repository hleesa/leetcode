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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        while(cur->next){
            ListNode* node = new ListNode(gcd(cur->val, cur->next->val));
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        return head;
    }
private:
    int gcd(int a, int b){
        int c;
        while(b){
            c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
};