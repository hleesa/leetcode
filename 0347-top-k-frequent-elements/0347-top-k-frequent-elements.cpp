class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> counter;
        for(const auto& num : nums){
            ++counter[num];
        }
        vector<pair<int,int>> candi;
        for(const auto& it : counter){
            candi.push_back({it.second, it.first});
        }
        sort(candi.begin(), candi.end(), std::greater<pair<int,int>>());
        vector<int> ans;
        for(int i = 0; i < min((int)candi.size(), k); ++i){
            ans.push_back(candi[i].second);
        }
        return ans;
    }
};