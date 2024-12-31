class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.back()+1);
        int i = 0;

        for(int day = 1; day <= days.back(); ++day){
            if(day < days[i]){
                dp[day] = dp[day-1];
            }
            else{
                dp[day] = min({dp[day-1] + costs[0], dp[max(day-7,0)] + costs[1], dp[max(day-30,0)] + costs[2] });
                ++i;
            }
        }

        return dp[days.back()];
    }
};