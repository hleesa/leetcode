class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> counter(k);
        for(int num : arr){
            int rem = ((num%k)+k)%k;
            ++counter[rem];
        }

        if(counter[0] % 2 != 0){
            return false;
        }
        for(int i=1; i <= k/2; ++i){
            if(counter[i] != counter[k-i]){
                return false;
            }
        }
        return true;
    }
};