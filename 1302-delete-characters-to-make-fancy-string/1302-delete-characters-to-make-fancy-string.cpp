class Solution {
public:
    string makeFancyString(string s) {
        if(s.length() < 3){
            return s;
        }
        string fancyStr = s.substr(0, 2);
        int counter[26] = {0};
        ++counter[s[0]-'a'];
        ++counter[s[1]-'a'];

        for(int i = 2; i < s.length(); ++i){
            int inIdx = s[i] - 'a';
            ++counter[inIdx];
            if(counter[inIdx] < 3){
                fancyStr.push_back(s[i]);
            }
            --counter[s[i-2] - 'a'];
        }

        return fancyStr;
    }
};