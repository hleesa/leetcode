class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        vector<string> words;
        string word;

        while(ss >> word){
            words.push_back(word);
        }

        for(int i = 0; i + 1 < words.size(); ++i){
            if(words[i].back() != words[i+1].front()){
                return false;
            }
        }
        return words.front().front() == words.back().back();
    }
};