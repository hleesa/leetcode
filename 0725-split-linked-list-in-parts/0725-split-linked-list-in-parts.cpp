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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        while(cur){
            ++n;
            cur = cur->next;
        }
        vector<ListNode*> ans(k);
        vector<int> listSize(k, n/k);
        for(int i =0; i < n%k; ++i){
            ++listSize[i];
        }

        cur = head;
        for(int i = 0; i < k; ++i){
            ans[i] = cur;
            ListNode* prev = nullptr;;
            for(int j = 0; j < listSize[i]; ++j){
                prev = cur;
                cur = cur->next;
            }
            if(prev){
                prev->next = nullptr;
            }
        }
        return ans;
    }
};