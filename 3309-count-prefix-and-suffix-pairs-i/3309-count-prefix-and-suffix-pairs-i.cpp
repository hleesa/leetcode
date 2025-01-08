class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i = 0; i < words.size(); ++i){
            for(int j = i + 1; j < words.size(); ++j){
                if(isPrefixAndSuffix(words[i], words[j])){
                    ++ans;
                }
            }
        }
        return ans;
    }

    bool isPrefixAndSuffix(string str1, string str2){
        const int len1 = str1.length();
        const int len2 = str2.length();
        if(len1 > len2) return false;
        return str2.compare(0, len1, str1) == 0 && str2.compare(len2-len1, len1, str1) == 0;
    }
};