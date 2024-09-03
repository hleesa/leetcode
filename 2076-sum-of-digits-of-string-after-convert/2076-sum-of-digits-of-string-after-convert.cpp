class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        for(auto c : s){
            int n = c - 'a' + 1;
            while(n > 0){
                ans += n % 10;
                n /= 10;
            }
        }
        for(int i = 1; i < k; ++i){
            int digits = 0;
            while(ans > 0){
                digits += ans % 10;
                ans /= 10;
            }
            ans = digits;
        }
        return ans;
    }
};