class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        for(int i = 1; i < 10; ++i){
            dfs(i, n, ret);
        }
        return ret;
    }
private:
    void dfs(int cur, int n, vector<int>& ret){
        if (cur > n){
            return;
        }
        ret.push_back(cur);
        for(int i = 0; i < 10; ++i){
            if(cur * 10 + i > n) return;
            dfs(cur*10+i, n, ret);
        }
    }
};