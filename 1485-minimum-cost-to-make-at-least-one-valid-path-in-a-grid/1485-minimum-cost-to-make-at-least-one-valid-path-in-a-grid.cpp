class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int yEnd = grid.size();
        const int xEnd = grid.front().size();
        vector<vector<int>> minCost(yEnd, vector<int>(xEnd, 987654321));
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        deque<pair<int,int>> dq;

        dq.push_front({0,0});
        minCost[0][0] = 0;

        while(!dq.empty()){
            auto [y, x] = dq.front();
            dq.pop_front();

            for(int d = 0; d < 4; ++d){
                int ny = y + dirs[d][0];
                int nx = x + dirs[d][1];
                int cost = (grid[y][x] != d + 1) ? 1 : 0;

                if(ny < 0 || ny >= yEnd || nx < 0 || nx >= xEnd) continue;
                else if(minCost[y][x] + cost < minCost[ny][nx]){
                    minCost[ny][nx] = minCost[y][x] + cost;

                    if(cost == 1){
                        dq.push_back({ny,nx});
                    }
                    else{
                        dq.push_front({ny,nx});
                    }
                }
            }
        }

        return minCost[yEnd-1][xEnd-1];
    }
};