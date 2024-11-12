class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        map<int, int> ptob;
        for(const auto& item : items){
            int price = item.front();
            int beauty = item.back();
            if (beauty > ptob[price]){
                ptob[price] = beauty;
            }
        }
        for(auto it = ptob.begin(); next(it) != ptob.end(); ++it){
            auto nextIt = next(it);
            nextIt->second = max(nextIt->second, it->second);
        }

        map<int,int, std::greater<int>> priceToBeauty(ptob.begin(), ptob.end());
        vector<int> ans;
        for(const auto& q : queries){
            ans.push_back(priceToBeauty.lower_bound(q)->second);
        }
        return ans;
    }
};