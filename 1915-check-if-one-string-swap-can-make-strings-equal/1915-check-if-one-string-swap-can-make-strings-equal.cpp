class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> indices;
        for(int i = 0 ; i < s1.length(); ++i){
            if(s1[i] != s2[i]){
                indices.push_back(i);
            }
        }
        if(indices.empty()) return true;
        else if (indices.size() == 2){
            swap(s2[indices[0]], s2[indices[1]]);
            return s1 == s2;
        }
        return false;
    }
};