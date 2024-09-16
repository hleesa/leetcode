class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        const int n = timePoints.size() + 1;
        vector<int> minutes(n);
        for(int i = 0; i + 1 < n; ++i){
            minutes[i] = toMinute(timePoints[i]);
        }
        sort(minutes.begin(), minutes.begin() + n - 1);
        minutes[n-1] = minutes.front() + 60 * 24;

        int ans = 25 * 60;
        for(int i = 0; i + 1 < n ; ++i){
            int diff = minutes[i+1] - minutes[i];
            if (diff < ans){
                ans = diff;
            }
        }
        return ans;
    }
private:
    int toMinute(const string& timePoint){
        stringstream ss(timePoint);
        int time[2];
        char colon;
        ss >> time[0] >> colon >> time[1];
        int minute = 60 * time[0] + time[1];
        if (minute == 0){
            minute = 24 * 60;
        }
        return minute;
    }
};