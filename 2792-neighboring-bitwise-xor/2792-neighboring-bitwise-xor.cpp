class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans = 0;
        for(auto e : derived){
            ans ^= e;
        }
        return ans == 0;
    }
};