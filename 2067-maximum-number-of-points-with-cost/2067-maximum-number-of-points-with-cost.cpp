class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        const int yMax = points.size();
        const int xMax = points.front().size();
        vector<long long> prev(xMax);
        vector<long long> curr(xMax);

        for(int x=0; x < xMax; ++x){
            prev[x] = points.front()[x];
        }

        for(int y = 1; y < yMax; ++y){
            vector<long long> left(xMax);
            vector<long long> right(xMax);

            left[0] = prev[0];
            for(int x = 1; x < xMax; ++x){
                left[x] = max(left[x-1]-1, prev[x]);
            }

            right[xMax-1] = prev[xMax-1];
            for(int x = xMax-2; x >= 0; --x){
                right[x] = max(right[x+1]-1, prev[x]);
            }

            for(int x= 0; x < xMax; ++x){
                curr[x] = points[y][x] + max(left[x], right[x]);
            }

            prev = curr;
        }

        return *max_element(prev.begin(), prev.end());
    }
};