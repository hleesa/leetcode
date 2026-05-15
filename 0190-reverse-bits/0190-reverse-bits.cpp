class Solution {
public:
    int reverseBits(int n) {
        int result = 0;
        for(int i = 0; i < 32; ++i){
            int bit = (n >> i) & 1;
            result <<= 1;
            result |= bit;
        }

        return result;
    }
};