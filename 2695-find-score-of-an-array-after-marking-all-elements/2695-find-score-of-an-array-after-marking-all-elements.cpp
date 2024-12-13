class Solution {
public:
    long long findScore(vector<int>& nums) {
        const int n = nums.size();
        vector<pair<int,int>> numIdx(n);
        for(int i = 0; i < n; ++i){
            numIdx[i] = {nums[i], i};
        }

        sort(numIdx.begin(), numIdx.end());
        vector<bool> vis(n);
        long long ans = 0;
        
        for(const auto& it : numIdx){
            if(vis[it.second]) continue;
            ans += it.first;
            vis[it.second] = true;
            if (it.second > 0) vis[it.second - 1] = true;
            if (it.second + 1 < n) vis[it.second + 1] = true;
        }

        return ans;
    }
};