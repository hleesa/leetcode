class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        const int alphaLen = 26;
        int word2[alphaLen] = {0};
        for(const auto& str : words2){
            int candi[alphaLen] = {0};
            for(auto ch : str){
                ++candi[ch-'a'];
            }
            for(int i = 0 ; i < alphaLen; ++i){
                word2[i] = max(candi[i],word2[i]);
            }
        }

        vector<string> ans;
        for(const auto& word : words1){
            int word1[alphaLen] = {0};
            for(auto ch : word){
                ++word1[ch-'a'];
            }
            bool subset = true;
            for(int i = 0 ; i < alphaLen; ++i){
                if (word1[i] < word2[i]){
                    subset = false;
                    break;
                }
            }
            if(subset){
                ans.push_back(word);
            }
        }
        return ans;
    }
};