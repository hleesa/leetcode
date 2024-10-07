class Solution {
public:
    int minLength(string s) {
        size_t a, c;
        while((a = s.find("AB")) != string::npos || (c = s.find("CD")) != string::npos){
            if (a != string::npos){
                s.erase(a,2);
                continue;
            }
            if (c != string::npos){
                s.erase(c,2);
            }
        }
        return s.length();
    }
};