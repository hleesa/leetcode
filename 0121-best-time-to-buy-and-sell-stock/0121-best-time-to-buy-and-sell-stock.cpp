class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        int minP = prices.front();
        int ans = 0;
        for(int i = 1; i < n; ++i){
            ans = max(prices[i] - minP, ans);
            minP = min(prices[i], minP);
        }
        return ans;
    }
};