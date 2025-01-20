class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int m = mat.size();
        const int n = mat.front().size();
        vector<int> mCount(m), nCount(n);
        vector<pair<int,int>> numToPos(m*n+2);
        for(int y = 0; y < m; ++y){
            for(int x = 0; x <n; ++x){
                numToPos[mat[y][x]] = {y,x};
            }
        }
        for(int i = 0; i < arr.size(); ++i){
            int num = arr[i];
            ++mCount[numToPos[num].first];
            ++nCount[numToPos[num].second];
            if (mCount[numToPos[num].first] == n || nCount[numToPos[num].second] == m){
                return i;
            }
        }
        return -1;
    }
};