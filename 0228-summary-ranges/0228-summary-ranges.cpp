class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for(size_t i = 0 ; i < nums.size();){
            long long begin = i;
            long long end = i + 1;
            while(end < nums.size() && (long long)nums[end] - nums[begin] == end - begin){
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