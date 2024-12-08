class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& l, const vector<int>r){
            return l[0] < r[0];
        });

        const int n = events.size();
        vector<int> suffixMax(n);
        suffixMax[n-1] = events[n-1][2];
        for(int i = n - 2; i >= 0; --i){
            suffixMax[i] = max(events[i][2], suffixMax[i+1]);
        }

        int ans = 0;
        for(int i = 0; i < n; ++i){
            int left = i + 1, right = n;
            int nextIndex = -1;

            while(left < right){
                int mid = left + (right - left) / 2;
                if(events[i][1] < events[mid][0]){
                    nextIndex = mid;
                    right = mid;
                }
                else{
                    left = mid + 1;
                }
            }
            
            if(nextIndex != -1){
                ans = max(events[i][2] + suffixMax[nextIndex], ans);
            }
            ans = max(events[i][2], ans);
        }

        return ans;
    }
};