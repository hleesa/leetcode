class Solution {
public:
    string compressedString(string word) {
        string comp;
        const int n = word.length();
        for(int i = 0; i < n;){
            int j = i + 1;
            while(j < n && word[i] == word[j]) ++j;
            int cnt = j - i;
            for(int k = 0; k < cnt / 9; ++k){
                string str = "9" + string(1, word[i]);
                comp += str;
            }
            if(cnt%9 > 0){
                string str = string(1, cnt%9+'0') + string(1, word[i]);
                comp += str;
            }
            i += j - i;
        }
        return comp;
    }
};