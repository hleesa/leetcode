class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int yEnd = isWater.size();
        const int xEnd = isWater.front().size();
        vector<vector<int>> height(yEnd, vector<int>(xEnd, -1));
        queue<pair<int,int>> q;
        for(int y = 0; y < yEnd; ++y){
            for(int x = 0; x < xEnd; ++x){
                if(isWater[y][x]){
                    q.push({y,x});
                    height[y][x] = 0;
                }
            }
        }

        vector<vector<int>> dirs ={{-1,0}, {1,0}, {0, -1}, {0,1}};
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i){
                int ny = cur.first + dirs[i][0];
                int nx = cur.second + dirs[i][1];
                if(ny < 0 || ny >= yEnd || nx < 0 || nx >= xEnd) continue;
                else if (height[ny][nx] != -1) continue;
                height[ny][nx] = height[cur.first][cur.second] + 1;
                q.push({ny,nx});
            }
        }

        return height;
    }
};;