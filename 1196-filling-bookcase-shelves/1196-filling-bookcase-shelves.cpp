class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int size = books.size();
        vector<int> dp(size+2, INT_MAX);
        dp[0] = 0;

        for(int i=1; i <=size; ++i){
            int width = 0;
            int height = 0;
            for(int j = i; j > 0; --j){
                width += books[j-1][0];
                if(width > shelfWidth) break;
                height = max(height, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1] + height);
            }
        }
        return dp[size];
    }
};