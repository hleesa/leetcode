class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        const int ySize = grid.size();
        const int xSize = grid.front().size();
        vector<vector<bool>> visited(ySize, vector<bool>(xSize, false));

        int maxFish = 0;
        for(int y = 0; y < ySize; ++y){
            for(int x = 0; x < xSize; ++x){
                if(visited[y][x] || grid[y][x] == 0) continue;
                maxFish = max(fish(grid, visited, y, x), maxFish);
            }
        }

        return maxFish;
    }

private:
    const vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    int fish(const vector<vector<int>>& grid, vector<vector<bool>> visited, int sy, int sx){
        const int ySize = grid.size();
        const int xSize = grid.front().size();
        queue<pair<int,int>> q;
        q.push({sy,sx});
        visited[sy][sx] = true;
        int numFish = grid[sy][sx];

        while(!q.empty()){
            auto [y, x] = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i){
                int ny = y + dirs[i][0];
                int nx = x + dirs[i][1];
                if (ny < 0 || ny >= ySize || nx < 0 || nx >= xSize) continue;
                else if (visited[ny][nx] || grid[ny][nx] == 0) continue;
                visited[ny][nx] = true;
                numFish += grid[ny][nx];
                q.push({ny,nx});
            }
        }

        return numFish;
    }
};