class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        const int n = colors.size();
        int numAjDiff = 0;
        for(int i = 0; i + 1 < k; ++i){
            if(colors[i] != colors[i+1]) ++numAjDiff;
        }
        int numAG = 0;
        if (numAjDiff + 1 == k) ++numAG;
        for(int i = 1; i < n; ++i){
            if (colors[i-1] != colors[i]) --numAjDiff;
            if (colors[(i+k-2)%n] != colors[(i+k-1)%n]) ++numAjDiff;
            if (numAjDiff + 1 == k) ++numAG;
        }
        return numAG;
    }
};