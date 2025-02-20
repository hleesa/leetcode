class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> numSet(nums.begin(), nums.end());
        string ans;
        find(numSet, "", ans, nums[0].length());
        return ans;
    }
    bool find(const set<string>& numSet, string cur, string& ans, int len){
        if(cur.length() == len){
            if(numSet.contains(cur)) return false;
            ans = cur;
            return true;
        }
        if(find(numSet, cur + "0", ans, len)) return true;
        if(find(numSet, cur + "1", ans, len)) return true;
        return false;
    }
};