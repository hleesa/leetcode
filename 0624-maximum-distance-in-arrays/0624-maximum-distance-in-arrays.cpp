class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        multiset<int> ms;
        for(const auto& array : arrays){
            ms.insert(array.begin(), array.end());
        }

        int maxdiff = 0;
        for(const auto& array : arrays){
            for(auto n : array){
                auto it = ms.find(n);
                ms.erase(it);
            }
            if (!ms.empty()){
                maxdiff = max({abs(*ms.rbegin() - array.front()), abs(array.back() - *ms.begin()), maxdiff});
            }
            for(auto n : array){
                ms.insert(n);
            }
        }

        return maxdiff;
    }
};