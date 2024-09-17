class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> words;
        vector<string> s1vec = split(s1);
        vector<string> s2vec = split(s2);
        for(const string& word : s1vec){
            ++words[word];
        }
        for(const string& word : s2vec){
            ++words[word];
        }

        vector<string> ret;
        for(const auto& it : words){
            if(it.second == 1){
                ret.push_back(it.first);
            }
        }
        return ret;
    }

private:
    vector<string> split(const string& s){
        vector<string> ret;
        stringstream ss(s);
        string word;
        while(ss >> word){
            ret.push_back(word);
        }
        return ret;
    }
};