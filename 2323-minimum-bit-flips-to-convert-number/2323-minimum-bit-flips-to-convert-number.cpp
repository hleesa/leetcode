class Solution {
public:
    int minBitFlips(int start, int goal) {        
        int ret = 0;
        int num = start ^ goal;
        for(int i = 0; (1 << i) <= num; ++i){
            if((num & (1 << i))){
                ++ret;
            }
        }
        return ret;
    }
};