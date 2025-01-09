class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(const auto& word : words){
            if(word.length() < pref.length()) continue;
            else if(word.compare(0, pref.length(), pref) == 0){
                ++ans;
            }
        }
        return ans;
    }
};