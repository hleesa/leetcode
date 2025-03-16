class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0, r = queries.size();

        if(!zeroArray(nums, queries, r)) return -1;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if (zeroArray(nums, queries, mid)){
                r = mid -1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }

    bool zeroArray(const vector<int>& nums, const vector<vector<int>>& queries, int k){
        const int n = nums.size();
        vector<int> diffArr(n+1);
        for(int i = 0; i < k; ++i){
            int l = queries[i][0], r = queries[i][1], v = queries[i][2];
            diffArr[l] += v;
            diffArr[r+1] -= v;
        }

        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += diffArr[i];
            if(sum < nums[i]) return false;
        }
        return true;
    }
};