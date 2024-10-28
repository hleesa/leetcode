class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<long long> numSet(nums.begin(), nums.end());
        set<long long> vis;
        int ans = 0;
        for(long long n : numSet){
            if(vis.contains(n)) continue;
            int candi = 1;
            while(numSet.contains(n*n)){
                ++candi;
                n = n*n;
                vis.insert(n*n);
            }
            if(candi > ans){
                ans = candi;
            }
        }
        if (ans == 1) ans = -1;
        return ans;
    }
};