class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNums(n, INT_MAX);
        const int coefSize = 3;
        vector<int> prevIdx(coefSize);
        vector<int> coef = {2,3,5};

        uglyNums[0] = 1;
        for(int i=1; i<n; ++i){
            for(int j = 0; j < coefSize; ++j){
                uglyNums[i] = min(coef[j] * uglyNums[prevIdx[j]], uglyNums[i]);
            }
            for(int j = 0; j < coefSize; ++j){
                if(coef[j] * uglyNums[prevIdx[j]] == uglyNums[i]){
                    ++prevIdx[j];
                }
            }
        }
        
        return uglyNums[n-1];
    }
};