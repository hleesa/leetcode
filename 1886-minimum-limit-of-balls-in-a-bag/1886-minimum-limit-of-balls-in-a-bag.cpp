class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = 1e9 + 1;
        int ans = r;
        
        while(l < r){
            int target = l + (r-l) / 2;
            
            if(divide(nums, maxOperations, target)){
                ans = target;
                r = target;
            }
            else{
                l = target + 1;
            }
        }
        return ans;
    }

private:
    bool divide(const vector<int>& nums, int maxOperations, int target){
        int size = 0;
        for(const int& num : nums){
            size += (num / target);
            if(num % target != 0) ++size;
        }
        return size <= (nums.size() + maxOperations);
    }
};

