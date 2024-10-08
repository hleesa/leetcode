class Solution {
public:
    int minSwaps(string s) {
        int ret = 0;
        stack<char> stk;
        int back = 0;
        for(auto ch : s){
            if (ch == '['){
                stk.push(ch);
            }
            else if (stk.empty()){
                stk.push('[');
                ++ret;
            }
            else{
                stk.pop();
            }
        }
        return ret;
    }
};