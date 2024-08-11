class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        const int yEnd = grid.size();
        const int xEnd = grid.front().size();
        const int numIsland = countIsland(grid);

        if (numIsland != 1){
            return 0;
        }

        for (int y = 0; y < yEnd; ++y) {
            for (int x = 0; x < xEnd; ++x) {
                if(grid[y][x] == 1){
                    grid[y][x] = 0;
                    if(countIsland(grid) != numIsland){
                        return 1;
                    }
                    grid[y][x] = 1;
                }
            }
        }
        
        return 2;
    }

private:
    const int dy[4] = {-1, 1, 0, 0};
    const int dx[4] = {0, 0, -1, 1};

    int bfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, const int y, const int x){
        queue<pair<int,int>> q;
        q.push({y,x});
        visited[y][x] = true;
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i){
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];
                if (ny < 0 || ny >= grid.size() || nx < 0 || nx >= grid.front().size()){
                    continue;
                }
                else if (grid[ny][nx] != 1 || visited[ny][nx]){
                    continue;
                }
                visited[ny][nx] = true;
                q.push({ny,nx});
            }
        }
        return 1;
    }

    int countIsland(const vector<vector<int>>& grid){
        const int yEnd = grid.size();
        const int xEnd = grid.front().size();
        vector<vector<bool>> visited(yEnd, vector<bool>(xEnd));
        int numIsland = 0;

        for(int y = 0 ; y < yEnd; ++y){
            for(int x = 0; x < xEnd; ++x){
                if(grid[y][x] != 1 || visited[y][x]) continue;
                numIsland += bfs(grid, visited, y, x);
            }
        }
        return numIsland;
    }
};
