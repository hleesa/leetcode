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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> delNum(nums.begin(), nums.end());
        while (head != nullptr && delNum.contains(head->val)){
            head = head->next;
        }
        if(head == nullptr){
            return nullptr;
        }

        ListNode* cur = head;
        while(cur->next != nullptr){
            if(delNum.contains(cur->next->val)){
                ListNode* delNode = cur->next;
                cur->next = cur->next->next;
                delete (delNode);
            }
            else{
                cur = cur->next;
            }
        }
        return head;
    }
};