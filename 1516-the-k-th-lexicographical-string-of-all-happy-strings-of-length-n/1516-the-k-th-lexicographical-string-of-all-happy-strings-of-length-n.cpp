class Solution {
public:
    string ans;
    string getHappyString(int n, int k) {
        int cur = 0;
        getHappyString(n,k,"", cur);
        return ans;
    }
    void getHappyString(int n, int k, string candi, int& cur){
        if (candi.length() == n){
            ++cur;
            if(cur == k){
                ans = candi;
            }
            return;
        }
        for(int i = 0; i < 3; ++i){
            if(candi.empty()){
                candi += 'a' + i;
                getHappyString(n, k, candi, cur);
                candi.pop_back();
            }
            else{
                if (candi.back() == 'a' + i) continue;
                candi += 'a' + i;
                getHappyString(n, k, candi, cur);
                candi.pop_back();
            }
        }
        return;
    }
};