class Solution {
public:
    long long minimumSteps(string s) {
        long long steps = 0, ones = 0;
        for(auto c : s){
            if (c == '1'){
                ++ones;
            }
            else{
                steps += ones;
            }
        }
        
        return steps;
    }
};
