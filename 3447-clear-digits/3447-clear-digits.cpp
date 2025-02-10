class Solution {
public:
    string clearDigits(string s) {
        vector<char> vec;
        for(int i = 0; i < s.length(); ++i){
            char ch = s[i];
            if(isdigit(ch)){
                if(vec.empty()){
                    return s.substr(i);
                }
                else{
                    vec.pop_back();
                }
            }
            else{
                vec.push_back(ch);
            }
        }
        return string(vec.begin(), vec.end());
        
    }
};