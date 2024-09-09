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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ret(m, vector<int>(n, -1));
        vector<int> cur{0,0,0};
        while(head){
            ret[cur[0]][cur[1]] = head->val;
            int ny = cur[0] + dy[cur[2]];
            int nx = cur[1] + dx[cur[2]];
            if (ny < 0 || ny >= m || nx < 0 || nx >=n || ret[ny][nx] != -1){
                cur[2] = (cur[2] + 1) %4;
                ny = cur[0] + dy[cur[2]];
                nx = cur[1] + dx[cur[2]];
            }
            cur = {ny,nx,cur[2]};
            head = head->next;
        }
        return ret;
    }
private:
    const int dy[4] = {0,1,0,-1};
    const int dx[4] = {1,0,-1,0};
};