class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for(int i = 0 ; i < nums.size();){
            size_t begin = i;
            size_t end = i + 1;
            while(end < nums.size() && nums[end] == nums[end-1] + 1){
                ++end;
            }

            string an;
            if(begin + 1 == end){
                an = to_string(nums[begin]);
            }
            else{
                an = to_string(nums[begin]) + "->" + to_string(nums[end-1]);
            }

            ans.push_back(an);
            i = end;
        }

        return ans;
    }
};