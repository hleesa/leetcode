class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        const int n = arr.size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if (i == j) continue;
                else if(2 * arr[i] == arr[j]) return true;
            }
        }
        return false;
    }
};