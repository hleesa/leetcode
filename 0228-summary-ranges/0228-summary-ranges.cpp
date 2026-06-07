class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for(size_t i = 0 ; i < nums.size();){
            long long off = 1;
            while(i + off < nums.size() && nums[i+off] - off == nums[i]){
                ++off;
            }

            string range;
            if(off == 1){
                range = to_string(nums[i]);
            }
            else{
                range = to_string(nums[i]) + "->" + to_string(nums[i+off-1]);
            }

            ans.push_back(range);
            i += off;
        }
        
        return ans;
    }
};