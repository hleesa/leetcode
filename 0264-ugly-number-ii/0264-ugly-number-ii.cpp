class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> uglyNum = {1};
        for(auto it = uglyNum.begin(); uglyNum.size() < 2*n; ++it){
            int mul[3] = {2,3,5};
            for(int i=0; i < 3 && uglyNum.size() < 2*n; ++i){
                uglyNum.insert((*it)*mul[i]);
            }
            
        }
        return *next(uglyNum.begin(),n-1);
    }
};