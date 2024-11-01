class Solution {
public:
    string makeFancyString(string s) {
        string fancyStr;
        int counter[26] = {0};

        for(int i = 0; i < s.length(); ++i){
            int inIdx = s[i] - 'a';
            ++counter[inIdx];
            
            if(counter[inIdx] < 3){
                fancyStr.push_back(s[i]);
            }
            if(i >= 2){
                --counter[s[i-2] - 'a'];
            }
        }

        return fancyStr;
    }
};