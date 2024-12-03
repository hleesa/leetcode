class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        set<int> space(spaces.begin(), spaces.end());
        string ans;
        for(int i = 0; i < s.length(); ++i){
            if (space.contains(i)){
                ans.push_back(' ');
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};