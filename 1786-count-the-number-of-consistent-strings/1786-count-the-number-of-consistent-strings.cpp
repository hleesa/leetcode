class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> allowedChar(allowed.begin(), allowed.end());
        int ret = 0;
        for(const string& word : words){
            int i;
            int len = word.length();
            for(i = 0; i < len; ++i ){
                if(!allowedChar.contains(word[i])) break;
            }
            if(i == len){
                ++ret;
            }
        }
        return ret;
    }
};