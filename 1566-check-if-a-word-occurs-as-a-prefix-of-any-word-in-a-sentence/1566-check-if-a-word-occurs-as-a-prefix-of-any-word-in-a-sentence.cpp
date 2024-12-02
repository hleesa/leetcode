class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        for(int i = 1; ss >> word; ++ i){
            if(word.compare(0, searchWord.length(), searchWord) == 0){
                return i;
            }
        }
        return -1;
    }
};