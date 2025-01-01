class Solution {
public:
    int maxScore(string s) {
        int numOne = std::count(s.begin(), s.end(), '1');
        int numZero = 0;
        int maxScore = 0;
        for(int i = 0; i + 1< s.length(); ++i){
            if(s[i] == '0'){
                ++numZero;
            }
            else{
                --numOne;
            }
            maxScore = max(numZero + numOne, maxScore);

        }
        return maxScore;
    }
};