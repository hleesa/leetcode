class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, sorted = 0, cur = 0;
        for(int i = 0; i < arr.size(); ++i){
            cur |= (1 << arr[i]);
            sorted |= (1 << i);
            if (cur == sorted){
                cur = 0;
                sorted = 0;
                ++ans;
            }
        }
        return ans;
    }
};