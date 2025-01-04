class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for(char c : s){
            letters.insert(c);
        }

        int ans = 0;
        for(char letter : letters){
            int l = -1;
            int r = 0;
            for(int i = 0; i < s.length(); ++i){
                if(s[i] == letter){
                    if (l == -1){
                        l = i;
                    }
                    r = i;
                }
            }
            
            unordered_set<char> between;
            for(int i = l + 1; i < r; ++i){
                between.insert(s[i]);
            }
            ans += between.size();
        }

        return ans;
    }
};