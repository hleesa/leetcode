class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        for(int i = 0; i < 32; ++i){
            int mask = 1 << i;
            if(mask & n){
                ++ans;
            }
        }

        return ans;
    }
};