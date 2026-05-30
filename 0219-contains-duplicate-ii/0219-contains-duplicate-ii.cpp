class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> numToIndices;
        for(size_t i = 0 ; i < nums.size(); ++i){
            numToIndices[nums[i]].push_back(i);
        }
        
        for(const auto& [_, is] : numToIndices){
            for(int i = 0; i + 1 < is.size(); ++i){
                if(is[i+1] - is[i] <= k) return true;
            }
        }

        return false;
    };
};