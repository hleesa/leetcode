class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mulToNum;
        const int n = nums.size();
        for(int i = 0; i + 1< n; ++i){
            for(int j = i + 1; j < n; ++j){
                mulToNum[nums[i]* nums[j]]++;
            }
        }

        int numTutples = 0;
        for(auto it : mulToNum){
            if(it.second > 1){
                numTutples +=  2 * (it.second) * 2 * (it.second-1);
            }
        }

        return numTutples;
    }
};

