class Solution {
public:
    int getLucky(string s, int k) {
        string str = convert(s);
        for(int i = 0; i < k; ++i){
            str = transform(str);
        }
        return stoi(str);
    }
private:
    string convert(string s){
        string ret;
        for(const char c : s){
            ret += to_string(c - 'a' + 1);
        }
        return ret;
    }
    string transform(string s){
        int ret = 0;
        for(const char c : s){
            ret += c - '0';
        }
        return to_string(ret);
    }
};