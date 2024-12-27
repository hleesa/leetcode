class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        const int n = values.size();
        vector<int> maxLeftScore(n);

        maxLeftScore[0] = values[0];
        int maxScore = 0;

        for(int i = 1; i < n; ++i){
            int currentRightScore = values[i] - i;
            maxScore = max(maxLeftScore[i - 1] + currentRightScore, maxScore);
            
            int currentLeftScore = values[i] + i;
            maxLeftScore[i] = max(currentLeftScore, maxLeftScore[i-1]);
        }
        return maxScore;
    }
};