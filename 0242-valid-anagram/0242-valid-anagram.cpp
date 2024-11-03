class Solution {
public:
    bool isAnagram(string s, string t) {
        const int n = 26;
        int counter[n] = {0};
        for(char ch : s){
            ++counter[ch-'a'];
        }
        for(char ch : t){
            --counter[ch-'a'];
        }
        for(int i = 0; i < n; ++i){
            if(counter[i] != 0){
                return false;
            }
        }
        return true;
    }
};