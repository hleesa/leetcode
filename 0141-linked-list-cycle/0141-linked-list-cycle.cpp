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
        set<ListNode*> visited;
        return hasCycleHepler(head, visited);
    }

    bool hasCycleHepler(ListNode* head, set<ListNode*>& visited){
        if (head == NULL) return false;
        else if(visited.contains(head)) return true;
        visited.insert(head);
        return hasCycleHepler(head->next, visited);
    }
};