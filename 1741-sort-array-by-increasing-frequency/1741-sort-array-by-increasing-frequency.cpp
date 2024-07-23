class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        const int offset = 101;
        int freq[202] ={0};
        for(const auto& n : nums){
            ++freq[n+offset];
        }
        
        vector<int> ans = nums;
        sort(ans.begin(), ans.end(), [&](int lhs, int rhs){
            if(freq[lhs+offset] == freq[rhs+offset]){
                return lhs > rhs;
            }
            return freq[lhs+offset] < freq[rhs+offset];
        });

        return ans;
    }
};