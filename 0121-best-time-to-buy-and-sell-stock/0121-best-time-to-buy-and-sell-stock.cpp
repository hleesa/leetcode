class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minP = prices.front();
        for(int i = 1; i < prices.size(); ++i){
            ans = max(prices[i] - minP, ans);
            minP = min(prices[i], minP);
        }
        return ans;
    }
};