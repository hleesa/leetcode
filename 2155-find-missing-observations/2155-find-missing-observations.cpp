class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = mean * (rolls.size() + n);
        for(int roll : rolls){
            sum -= roll;
        }
        if (sum < 1 * n || 6*n < sum){
            return vector<int>();
        }
        vector<int> ret (n, sum / n);
        for(int i = 0; i < sum % n; ++i){
            ++ret[i];
        }
        return ret;
    }
};