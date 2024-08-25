class Solution {
public:
    int romanToInt(string s) {
        map<char, int> rToI = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        map<string, int> roToI = {{"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};
        int ret = 0;
        for(int i = 0; i < s.length(); ++i){
            string str;
            if (i + 1 < s.length()){
                str = s.substr(i,2);
            }
            if (roToI.find(str) != roToI.end()){
                ret += roToI[str];
                ++i;
            }
            else {
                ret += rToI[s[i]];
            }
        }
        return ret;
    }
};