class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> special;
        const int n = nums.size();
        for(int i = 0; i < n; ++i){
            int j = i;
            while(j + 1 < n && nums[i] % 2 == abs(nums[j + 1] % 2 - (j + 1 - i) % 2)) ++j;
            special.push_back({i,j});
            i = j;
        }

        vector<bool> ans;
        for(const auto& q : queries){
            int l = 0, r = special.size();
            int candi = r;
            while(l < r){
                int mid = l + (r-l)/2;
                if(special[mid].front() <= q.front()){
                    candi = mid;
                    l = mid + 1;
                }
                else{
                    r = mid;
                }
            }
            ans.push_back(q.back() <=special[candi].back());
        }

        return ans;
    }
};
