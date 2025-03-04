class Solution {
public:
    bool checkPowersOfThree(int n) {
        int t = 1;
        while(t < n){
            t *= 3;
        }
        while(n){
            if (n >= t) n -= t;
            if (n >= t) return false;
            t /= 3;
        }
        return true;
    }
};