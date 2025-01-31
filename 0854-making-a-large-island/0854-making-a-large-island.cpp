class Solution {
public:

    const vector<vector<int>> dirs ={{-1,0}, {1,0}, {0,-1}, {0,1}};
    vector<vector<int>> groupIdMap;
    vector<int> groupSize;

    int largestIsland(vector<vector<int>>& grid) {
        getGroupSize(grid);
        const int ySize = grid.size();
        const int xSize = grid[0].size();
        int maxArea = 0;

        for(int y = 0; y < ySize; ++y){
            for(int x = 0; x < xSize; ++x){
                if(grid[y][x] == 0){
                    set<int> adjGroup;
                    for(int i = 0; i < 4; ++i){
                        int ny = y + dirs[i][0];
                        int nx = x + dirs[i][1];
                        if(ny < 0 || ny >= ySize || nx < 0 || nx >= xSize) continue;
                        else if (grid[ny][nx] == 1){
                            adjGroup.insert(groupIdMap[ny][nx]);
                        }
                    }

                    int newSize = 1;
                    for(int gid : adjGroup){
                        newSize += groupSize[gid];
                    }
                    maxArea = max(newSize, maxArea);
                }
            }
        }

        for(int size : groupSize){
            maxArea = max(size, maxArea);
        }
    
        return maxArea;
    }
    
    void getGroupSize(const vector<vector<int>>& grid){
        int id = 0;
        const int ySize = grid.size();
        const int xSize = grid[0].size();
        groupIdMap.assign(ySize, vector<int>(xSize, -1));

        for(int y = 0; y < ySize; ++y){
            for(int x = 0; x < xSize; ++x){
                if(grid[y][x] == 1 && groupIdMap[y][x] == -1){
                    groupSize.push_back(0);
                    bfs(grid, y, x, id++);
                }
            }
        }
    }

    void bfs(const vector<vector<int>>& grid, int sy, int sx, int id){
        queue<pair<int,int>> q;
        q.push({sy,sx});
        groupIdMap[sy][sx] = id;
        int size = 1;

        while(!q.empty()){
            auto [y, x] = q.front();
            q.pop();

            for(int i = 0; i < 4; ++i){
                int ny = y + dirs[i][0];
                int nx = x + dirs[i][1];
                
                if(ny < 0 || ny >= grid.size() || nx < 0 || nx >= grid[0].size()) continue;
                else if(grid[ny][nx] == 1 && groupIdMap[ny][nx] == -1){
                    groupIdMap[ny][nx] = id;
                    q.push({ny,nx});
                    ++size;
                }
            }
        }
        groupSize[id] = size;
    } 

};
