class Solution {
public:
    string getHappyString(int n, int k) {
        string ans;
        int cur = 0;
        backtrack(n, k, "", cur, ans);
        return ans;
    }

    void backtrack(int n, int k, string candi, int& cur, string& ans){
        if (candi.length() == n){
            ++cur;
            if(cur == k){
                ans = candi;
            }
            return;
        }
        for(char ch = 'a'; ch <= 'c'; ++ch){
            if(!candi.empty() && candi.back() == ch) continue;
            candi += ch;
            backtrack(n, k, candi, cur, ans);
            if (!ans.empty()) return;
            candi.pop_back();
        }
    }
};