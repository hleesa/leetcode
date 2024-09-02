class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long long> segSum(n);
        segSum[0] =  chalk[0];
        for(int i = 1; i < n; ++i){
            segSum[i] = segSum[i-1] + chalk[i];
        }
        if (k >= segSum[n-1]){
            k %= segSum[n-1];
        }
        int ans = 0;
        while(segSum[ans] <= k){
            ++ans;
        }
        return ans;
    }
};