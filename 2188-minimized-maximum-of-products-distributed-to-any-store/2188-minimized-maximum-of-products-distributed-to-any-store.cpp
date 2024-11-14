class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = 100001;
        int ans = 0;
        while(l < r){
            int mid = l + (r-l) / 2;
            int num = 0;
            if (mid != 0){
                for(int i = 0; i < quantities.size(); ++i){
                    num += (quantities[i] + mid - 1) / mid;
                }
            }
            if(num > n){
                l = mid + 1;
            }
            else {
                r = mid;
                ans = mid;
            }
        }
        return ans;
    }
};