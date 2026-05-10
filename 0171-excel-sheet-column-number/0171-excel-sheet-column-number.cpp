class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long ans = 0;
        for(auto ch : columnTitle){
            ans = ans * 26 + ch - 'A' + 1;
        }
        
        return static_cast<int>(ans);
    }
};