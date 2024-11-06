class Solution {
public:
    int minChanges(string s) {
        const int n = s.length();
        int ans = 0;
        for(int i = 0; i < n;){
            int j = i + 1;
            while(j < n && s[j] == s[i]){
                ++j;
            }
            if((j - i) % 2 == 1){
                ++ans;
                s[j] = 1 - s[j-1] - '0';
                i = j + 1;
            }
            else{
                i = j;
            }
        }
        return ans;
    }
};