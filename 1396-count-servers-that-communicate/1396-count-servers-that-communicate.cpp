class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int ySize = grid.size();
        const int xSize = grid.front().size();
        vector<vector<bool>> connected(ySize, vector<bool>(xSize, false));
        
        for(int y = 0; y < ySize; ++y){
            for(int x = 0; x < xSize; ++x){
                if(grid[y][x] == 0) continue;
                queue<pair<int,int>> q;
                for(int dy = 0; dy < ySize; ++dy){
                    if (grid[dy][x] == 1 && dy != y) q.push({dy,x});
                }
                for(int dx = 0; dx < xSize; ++dx){
                    if (grid[y][dx] == 1 && dx != x) q.push({y,dx});
                }
                if(!q.empty()){
                    while(!q.empty()){
                        connected[q.front().first][q.front().second] = true;
                        q.pop();
                    }
                    connected[y][x] = true;
                }
                
            }
        }

        int numServer = 0;
        for(int y = 0; y < ySize; ++y){
            for(int x = 0; x < xSize; ++x){
                if(connected[y][x]){
                    ++numServer;
                }
            }
        }
  
        return numServer;
    }
};