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
        return str2.find(str1) == 0 && str2.rfind(str1) == str2.length() - str1.length();
    }
};