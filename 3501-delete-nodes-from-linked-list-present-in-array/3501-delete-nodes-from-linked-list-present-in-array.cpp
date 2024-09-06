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
        ListNode* cur = head;
        ListNode* ret = nullptr;
        ListNode** retback = &ret;
        while(cur){
            if (delNum.find(cur->val) == delNum.end()){
                *retback = new ListNode(cur->val);
                retback = &(*retback)->next;
                cur = cur->next;
            }
            else{
                ListNode* delNode = cur;
                cur = cur->next;
                delete (delNode);
            }
        }
        return ret;
    }
};