class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        const int n = 24;
        vector<int> bits(n);
        for(int i = 0 ; i < n; ++i){
            for(int num : candidates){
                if((num & (1 << i)) > 0){
                    ++bits[i];
                }
            }
        }
        return *max_element(bits.begin(), bits.end());
    }
};