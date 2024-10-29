class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        const int YM = grid.size();
        const int XM = grid.front().size();
        vector<vector<int>> dp(YM, vector<int>(XM, 0));

        for(int x = 0; x + 1 < XM; ++x){
            for(int y = 0; y < YM; ++y){
                if(dp[y][x] < x) continue;

                if (grid[y][x] < grid[y][x+1]){
                    dp[y][x+1] = dp[y][x] + 1;
                }
                if (y > 0 && grid[y][x] < grid[y-1][x+1]){
                    dp[y-1][x+1] = dp[y][x] + 1;
                }
                if (y + 1 < YM && grid[y][x] < grid[y+1][x+1]){
                    dp[y+1][x+1] = dp[y][x] + 1;
                }
            }
        }
        
        int ans = 0;
        for(int y = 0; y < YM; ++y){
            for(int x = 0; x < XM; ++x){
                ans = max(dp[y][x],ans);
            }
        }

        return ans;
    }
};