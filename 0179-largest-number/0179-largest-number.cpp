class Solution {
private:
    static bool compare(int lhs, int rhs){
        string lhsStr = to_string(lhs);
        string rhsStr = to_string(rhs);
        string lhsrhs = lhsStr+rhsStr;
        string rhslhs = rhsStr+lhsStr;
        for(int i = 0; i < lhsrhs.length(); ++i){
            if(lhsrhs[i] == rhslhs[i]) continue;
            return lhsrhs > rhslhs;
        }
        return lhsrhs > rhslhs;
    }

public:
    string largestNumber(vector<int>& nums) {
        int i;
        for(i = 0; i < nums.size(); ++i){
            if(nums[i] == 0) continue;
            else break;
        }
        if(i == nums.size()){
            return "0";
        }
        sort(nums.begin(), nums.end(), compare);
        string ret;
        for(const int& num : nums){
            ret.append(to_string(num));
        }
        return ret;
    }

};