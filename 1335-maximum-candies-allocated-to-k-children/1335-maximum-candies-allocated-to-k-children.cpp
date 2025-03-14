class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int ans = 0;
        long long l = 1, r = INT_MAX;
        while(l < r){
            long long mid = l + (r-l) / 2;
            if(calloc(candies, mid, k)){
                ans = max((int)mid, ans);
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return ans;
    }

    bool calloc(const vector<int>& candies, int numCandy, long long k){
        long long numChildren = 0;
        for(auto candy : candies){
            numChildren += candy / numCandy;
        }
        return numChildren >= k;
    }
};
