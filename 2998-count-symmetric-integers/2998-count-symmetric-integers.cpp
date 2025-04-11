class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ret = 0;
        for(int x = low; x <= high; ++x){
            string numStr = to_string(x);
            const int n = numStr.size();
            if(n%2 != 0) continue;
            int sum[2] = {};
            for(int i = 0; i < n / 2; ++i){
                sum[0] += numStr[i];
                sum[1] += numStr[n - 1 - i];
            }
            if(sum[0] == sum[1]) ++ret;
        }
        return ret;
    }
};