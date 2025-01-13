class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26);
        for(char c : s){
            ++freq[c-'a'];
        }
        int numDel = 0;
        for(int i = 0; i < 26; ++i){
            if(freq[i] == 0) continue;
            else if(freq[i] % 2 == 0){
                numDel += freq[i] - 2;
            }
            else{
                numDel += freq[i] - 1;
            }
        }
        return s.length() - numDel;
    }
};
