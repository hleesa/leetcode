class Solution {
public:
    bool check(vector<int>& nums) {
        const int n = nums.size();
        for(int i = 0; i < n; ++i){
            bool asc = true;
            for(int j = 0; j + 1< n; ++j){
                if (nums[(i+j+1)%n] < nums[(i+j)%n]){
                    asc = false;
                    break;
                }
            }
            if(asc) return true;
        }
        return false;
    }
};