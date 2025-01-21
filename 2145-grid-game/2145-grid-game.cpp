class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        const int n = grid.front().size();
        vector<long long> top(n+1), bottom(n+1);

        for(int i = 0; i < n; ++i){
            top[i+1] = top[i] + grid[0][i];
            bottom[i+1] = bottom[i] + grid[1][i];
        }

        long long ans = LLONG_MAX;
        for(int x = 0; x < n; ++x){
            long long second = max(top[n] - top[x+1], bottom[x]);
            ans = min(second, ans);
        }

        return ans;
    }
};