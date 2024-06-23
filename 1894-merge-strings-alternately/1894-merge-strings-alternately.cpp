class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        result.reserve(word1.length() + word2.length());
        int i;
        for(i = 0; i < min(word1.length(),word2.length()); ++i){
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }

        if(i < word1.length()){
            result.insert(result.end(), word1.begin() + i, word1.end());
        }
        if(i < word2.length()){
            result.insert(result.end(), word2.begin() + i, word2.end());
        }

        return result;
    }

};