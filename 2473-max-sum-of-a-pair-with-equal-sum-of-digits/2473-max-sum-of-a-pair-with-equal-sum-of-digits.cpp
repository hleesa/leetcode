class Solution {
public:
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int,vector<int>> digitValue;
        for(int num : nums){
            digitValue[digitSum(num)].push_back(num);
        }
        int ans = -1;
        for(auto& [_, numVec] : digitValue){
            if(numVec.size() > 1){
                int candi = *numVec.rbegin() + *next(numVec.rbegin());
                if (candi > ans) ans = candi;
            }
        }
        return ans;
    }

    int digitSum(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};