class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const int n = words.size();
        vector<int> psum(n);
        if(hasVowel(words.front())){
            psum[0] = 1;
        }
        for(int i = 1; i < n; ++i){
            psum[i] = psum[i-1];
            if(hasVowel(words[i])){
                ++psum[i];
            }
        }

        vector<int> ans;
        for(const auto& q : queries){
            ans.push_back(psum[q.back()]);
            if(q.front() > 0){
                ans.back() -= psum[q.front() - 1];
            }
        }
        return ans;
    }

private:
    bool hasVowel(const string& word){
        string vowel = "aeiou";
        return vowel.find(word.front()) != std::string::npos && vowel.find(word.back()) != std::string::npos;
    }
};