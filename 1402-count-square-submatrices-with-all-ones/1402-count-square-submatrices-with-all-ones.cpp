class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int YMX = matrix.size();
        const int XMX = matrix.front().size();
        vector<vector<int>> dp(YMX , vector<int>(XMX));
        
        for(int y = 0 ; y < YMX; ++y){
            if(matrix[y][0] == 1) dp[y][0] = 1;
        }
        for(int x = 0; x < XMX; ++x){
            if(matrix[0][x] == 1) dp[0][x] = 1;
        }
        for(int y = 1; y < YMX; ++y){
            for(int x = 1; x < XMX; ++x){
                if(matrix[y][x] == 1){
                    dp[y][x] += min({dp[y-1][x-1], dp[y-1][x], dp[y][x-1]}) + 1;
                }
            }
        }

        int ans = 0;
        for(int y = 0 ; y < YMX; ++y){
            for(int x = 0; x < XMX; ++x){
                ans += dp[y][x];
            }
        }
        return ans;
    }
};