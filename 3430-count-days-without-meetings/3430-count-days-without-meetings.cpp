class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int offDays = 0, beforeEnd = 0;
        for(auto meet : meetings){
            int begin = meet.front(), end = meet.back();

            if(begin > beforeEnd + 1){
                offDays += begin - beforeEnd - 1;
            }
            beforeEnd = max(end, beforeEnd);
        }
        offDays += days - beforeEnd;

        return offDays;
    }
};