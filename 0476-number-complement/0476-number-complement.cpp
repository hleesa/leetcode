class Solution {
public:
    int findComplement(int num) {
        int acc = 0;
        int ans = 0;
        for(int i = 0; acc < num; ++i){
            int cur = (num & (1 << i));
            acc += cur;
            if(!cur){
                ans += (1 << i);
            }
        }
        return ans;
    }
};
