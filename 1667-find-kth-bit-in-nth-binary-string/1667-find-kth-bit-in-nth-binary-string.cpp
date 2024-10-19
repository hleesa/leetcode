class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i = 0; i < n; ++i){
            s = s + "1" + reverse(s);
        }
        return s[k-1];
    }
private:
    string reverse(string s){
        for(int i = 0; i < s.length(); ++i){
            s[i] = (s[i] - '0' ^ 1)  + '0';
        }
        ::reverse(s.begin(), s.end());
        return s;
    }
};