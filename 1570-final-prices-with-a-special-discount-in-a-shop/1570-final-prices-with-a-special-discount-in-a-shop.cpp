class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        const int n = prices.size();
        vector<int> answer = prices;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                if(prices[j] <= prices[i]){
                    answer[i] = prices[i] - prices[j];
                    break;
                }
            }
        }
        return answer;
    }
};