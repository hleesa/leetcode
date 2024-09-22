class Solution {
public:
    long long countStep(long long n, long long cur, long long next){
        long long step = 0;
        while(cur <= n){
            step += min(n+1, next) - cur;
            cur *= 10;
            next *= 10;
        }
        return step;
    }

    int findKthNumber(int n, int k) {
        long long cur = 1;
        --k;
        while(k > 0){
            long long step = countStep(n, cur, cur + 1);
            if (step <= k){
                ++cur;
                k -= step;
            }
            else{
                cur*= 10;
                --k;
            }
        }
        return cur;
    }
};