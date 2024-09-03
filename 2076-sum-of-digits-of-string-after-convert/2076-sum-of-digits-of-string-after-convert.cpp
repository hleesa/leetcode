class Solution {
public:
    int getLucky(string s, int k) {
        int ret = 0;
        for(auto c : s){
            int n = c - 'a' + 1;
            while(n){
                ret += n % 10;
                n /= 10;
            }
        }

        for(int i = 1; i < k; ++i){
            int digitSum = 0;
            while(ret){
                digitSum += ret % 10;
                ret /=10;
            }
            ret = digitSum;
        }
        return ret;
    }
};