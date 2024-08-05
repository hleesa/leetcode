class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> counter;
        for(const auto& str : arr){
            ++counter[str];
        }
        int kth = 0;
        for(const auto& str : arr){
            if(counter[str] != 1) continue;
            ++kth;
            if(kth == k){
                return str;
            }
        }
        return "";
    }
};