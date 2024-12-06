class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> ban(banned.begin(), banned.end());
        int cnt = 0, sum = 0;
        for(int i = 1; i <= n; ++i){
            if(ban.contains(i)) continue;
            else if(sum + i > maxSum) break;
            sum += i;
            ++cnt;
        }
        return cnt;
    }
};