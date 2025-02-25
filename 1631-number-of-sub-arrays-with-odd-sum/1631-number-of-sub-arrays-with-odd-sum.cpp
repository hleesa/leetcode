class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9+7;
        int ans = 0;
        int preSum = 0;
        int odd = 0, even = 1;
        for(auto num : arr){
            preSum += num;
            if(preSum % 2 == 0){
                ans += odd;
                ++even;
            }
            else{
                ans += even;
                ++odd;
            }
            ans %= mod;
        }

        return ans;
    }
};