class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minNum = k;
        for(int i = 0; i + k <= blocks.length(); ++i){
            int w = 0;
            for(int j = 0; j < k; ++j){
                if(blocks[i+j] == 'W') ++w;
            }
            minNum = min(w, minNum);
        }
        return minNum;
    }
};