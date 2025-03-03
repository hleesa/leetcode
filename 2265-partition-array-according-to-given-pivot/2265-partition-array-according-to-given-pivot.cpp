class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ret;
        for(int num : nums){
            if(num < pivot){
                ret.push_back(num);
            }
        }
        for(int num : nums){
            if(num == pivot){
                ret.push_back(num);
            }
        }
        for(int num : nums){
            if(num > pivot){
                ret.push_back(num);
            }
        }
        return ret;
    }
};