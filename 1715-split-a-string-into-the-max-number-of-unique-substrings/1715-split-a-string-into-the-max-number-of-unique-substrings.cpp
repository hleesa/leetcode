class Solution {
public:
    int maxUniqueSplit(string s) {
        return countMaxSplit(s, set<string>());
    }
private:
    int countMaxSplit(string s, set<string> subStr){
        if(s.empty()){
            return subStr.size();
        }
        int count = 0;
        for(int i = 1; i <= s.length(); ++i){
            string sub = s.substr(0, i);
            if (subStr.contains(sub)) continue;
            subStr.insert(sub);
            string nextSub = i < s.length() ? s.substr(i,s.length() - i) : "" ;
            count = max(count, countMaxSplit(nextSub, subStr));
            subStr.erase(sub);
        }
        return count;
    }
};