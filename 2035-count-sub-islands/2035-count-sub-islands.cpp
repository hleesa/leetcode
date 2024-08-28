class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        const int ySize = grid1.size();
        const int xSize = grid1.front().size();
        vector<vector<int>> numIslandGrid1(ySize, vector<int>(xSize, 0));
        int islandId = 0;
        for(int y = 0; y < ySize; ++y){
            for(int x = 0; x < xSize; ++x){
                if(grid1[y][x] == 1 && numIslandGrid1[y][x] == 0){
                    countIsland(grid1, numIslandGrid1, ++islandId, y,x);
                }
            }
        }
        
        vector<vector<int>> numIslandGrid2(ySize, vector<int>(xSize, 0));
        int numSubIsland = 0;
        for(int y = 0; y < ySize; ++y){
            for(int x = 0; x < xSize; ++x){
                if(grid2[y][x] == 1 && numIslandGrid2[y][x] == 0){
                    if (subIsland(numIslandGrid1, countIsland(grid2, numIslandGrid2, ++islandId, y,x))){
                        ++numSubIsland;
                    }
                }
            }
        }

        return numSubIsland;
    }
private:
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};

    bool subIsland(vector<vector<int>>& grid, queue<pair<int,int>> q){
        int y,x;
        map<int, int> counter;
        while(!q.empty()){
            tie(y,x) = q.front();
            q.pop();
            if(grid[y][x] == 0) return false;
            ++counter[grid[y][x]];
        }
        return counter.size() == 1;
    }

    queue<pair<int,int>> countIsland(vector<vector<int>>& grid, vector<vector<int>>& vis, int id, int sy, int sx){
        queue<pair<int,int>> ret;
        queue<pair<int,int>> q;
        vis[sy][sx] = id;
        q.push({sy,sx});
        ret.push({sy,sx});
        while(!q.empty()){
            int y,x;
            tie(y,x) = q.front();
            q.pop();
            for(int d = 0; d < 4; ++d){
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny < 0 || ny >= grid.size() || nx < 0 || nx >= grid.front().size()) continue;
                else if (vis[ny][nx] != 0 || grid[ny][nx] != 1 ) continue;
                vis[ny][nx] = id;
                q.push({ny,nx});
                ret.push({ny,nx});
            }
        }
        return ret;
    }
};