class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> stk;
        int ans = 0;
        for(const auto c : s){
            if(!stk.empty() && stk.top() == 'b' && c == 'a'){
                ++ans;
                stk.pop();
            }
            else{
                stk.push(c);
            }
        }
        return ans;
    }
};