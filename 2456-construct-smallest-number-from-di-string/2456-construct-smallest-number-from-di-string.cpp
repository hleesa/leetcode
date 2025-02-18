class Solution {
public:
    string smallestNumber(string pattern) {
        vector<bool> visitied(10, false);
        int ans = INT_MAX;
        for(int i = 1; i <= pattern.length() + 1; ++i){
            visitied[i] = true;
            ans = min(samllestNumber(0, i, visitied, pattern), ans);
            visitied[i] = false;
        }
        return to_string(ans);
    }

private:
    int samllestNumber(int dep, int num, vector<bool>& visitied, const string& pattern){
        if(dep == pattern.size()){
            return num;
        }
        int ret = INT_MAX;
        if (pattern[dep] == 'I'){
            for(int i = num % 10 + 1; i <= pattern.length() + 1; ++i){
                if (visitied[i]) continue;
                visitied[i] = true;
                ret = min(samllestNumber(dep + 1, num * 10 + i, visitied, pattern), ret);
                visitied[i] = false;
            }
        }
        else{
            for(int i = num % 10 - 1; i >= 1; --i){
                if(visitied[i]) continue;
                visitied[i] = true;
                ret = min(samllestNumber(dep + 1, num * 10 + i, visitied, pattern), ret);
                visitied[i] = false;
            }
        }
        return ret;
    }
};
