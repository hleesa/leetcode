class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<32> bit1(num1), bit2(num2), x;
        int one = bit2.count();
        for(int i = 31; i >=0 && one > 0; --i){
            if(bit1[i]){
                x.set(i);
                --one;
            }
        }
        for(int i = 0; one > 0 && i < 32; ++i){
            if(x[i]) continue;
            x.set(i);
            --one;
        }

        return x.to_ulong();
        
    }
};