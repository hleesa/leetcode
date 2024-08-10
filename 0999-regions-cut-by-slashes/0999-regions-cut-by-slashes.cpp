class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(3*n, vector<bool>(3*n, false));
        int regions = 0;

        for(int y = 0; y < n; ++y){
            for(int x = 0; x < n; ++x){
                if(grid[y][x] == '/'){
                    visited[3*y][3*x+2] = true;
                    visited[3*y+1][3*x+1] = true;
                    visited[3*y+2][3*x] = true;
                }
                else if (grid[y][x] == '\\'){
                    visited[3*y][3*x] = true;
                    visited[3*y+1][3*x+1] = true;
                    visited[3*y+2][3*x+2] = true;
                }
            }
        }

        for(int y = 0; y < 3*n; ++y){
            for(int x = 0; x < 3*n; ++x){
                if(!visited[y][x]){
                    dfs(visited,y,x);
                    ++regions;
                }
            }
        }

        return regions;
    }

private:
    void dfs(vector<vector<bool>>& visited, int y, int x){
        if (y < 0 || y >= visited.size() || x < 0 || x >= visited.size() || visited[y][x]){
            return;
        }
        visited[y][x] = true;
        dfs(visited, y+1, x);
        dfs(visited, y-1, x);
        dfs(visited, y, x+1);
        dfs(visited, y, x-1);
    }
};