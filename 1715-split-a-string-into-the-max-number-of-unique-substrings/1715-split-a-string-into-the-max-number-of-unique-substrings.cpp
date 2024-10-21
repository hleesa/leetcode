class Solution {
public:
    int maxUniqueSplit(string s) {
        set<string> seen;
        return backtrack(s, 0, seen);
    }
private:
    int backtrack(const string& s, int begin, set<string>& seen){
        if (begin == s.length()){
            return 0;
        }
        string current;
        int maxCount = 0;
        for(int i = begin; i < s.length(); ++i){
            current += s[i];
            if (seen.contains(current)) continue;
            seen.insert(current);
            maxCount = max(1 + backtrack(s, i + 1, seen), maxCount);
            seen.erase(current);
        }
        return maxCount;
    }
};