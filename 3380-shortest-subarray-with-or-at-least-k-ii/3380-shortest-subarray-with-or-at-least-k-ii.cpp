class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (k == 0 && !nums.empty()){
            return 1;
        }

        bits.resize(32, 0);
        const int n = nums.size();
        int l = 0, r = 0;
        int ans = INT_MAX;

        while(r < n){
            add(nums[r]);
            ++r;

            while(val >= k){
                ans = min(ans, r-l);
                sub(nums[l]);
                ++l;
                
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }

private:
    int val;
    vector<int> bits;

    int add(int num){
        val |= num;
        for(int i = 0 ; i <32; ++i){
            if(num & (1 << i)){
                ++bits[i];
            }
        }
        return val;
    }

    int sub(int num){
        for(int i = 0; i < 32; ++i){
            int mask = 1 << i;
            if(num & mask){
                --bits[i];
                if(bits[i] == 0){
                    val &= ~mask;
                }
            }
        }
        return val;
    }

};