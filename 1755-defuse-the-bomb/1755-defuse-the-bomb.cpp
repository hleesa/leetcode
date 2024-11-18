class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        const int n  = code.size();
        vector<int> dCode(n);
        for(int i = 0; i < n; ++i){
            int sum = 0;
            if(k > 0){
                for(int j = 1; j <= k; ++j){
                    sum += code[(i+j+n)%n];
                }
            }
            else{
                for(int j = -1; j >= k; --j){
                    sum += code[(i+j+n)%n];
                }
            }
            dCode[i] = sum;
        }
        return dCode;
    }
};