class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        const int arrSize = arr.size();
        vector<int> subXor(arrSize);
        subXor.front() = arr.front();
        for(int i = 1; i < arrSize; ++i){
            subXor[i] = subXor[i-1] ^ arr[i];
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for(const vector<int>& query : queries){
            ans.push_back(subXor[query.back()]);
            if(query.front() != 0){
                ans.back() ^= subXor[query.front()-1];
            }
        }
        return ans;
    }
};

