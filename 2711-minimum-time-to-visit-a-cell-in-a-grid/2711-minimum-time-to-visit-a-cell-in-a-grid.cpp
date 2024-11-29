class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
    
        const int Y_END = grid.size();
        const int X_END = grid.front().size();
        const int INF = 1e7;
        vector<vector<int>> dist(Y_END, vector<int>(X_END,INF));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        const int dy[4] = {-1,1,0,0};
        const int dx[4] = {0,0,-1,1};
        
        pq.push({0,0,0});
        dist[0][0] = 0;
        while(!pq.empty()){
            auto [t,y,x] = pq.top();
            pq.pop();

            if(y + 1 == Y_END && x + 1 == X_END){
                return t;
            }

            if (t > dist[y][x]) continue;

            for(int i = 0; i < 4; ++i){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= Y_END || nx < 0 || nx >= X_END) continue;

                int nt = max(t + 1, grid[ny][nx]);
                if ((nt - t) % 2 == 0){
                    ++nt;
                }
                if (nt < dist[ny][nx]) {
                    pq.push({nt, ny, nx});
                    dist[ny][nx] = nt;
                }
            }
        }

        return  -1;
    }
};