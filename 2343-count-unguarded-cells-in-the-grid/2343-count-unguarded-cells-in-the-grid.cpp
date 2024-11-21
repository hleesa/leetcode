class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        unordered_set<int> guard, wall;
        for(const auto& g : guards){
            guard.insert(g.front() * n + g.back());
        }
        for(const auto& w : walls){
            wall.insert(w.front() * n + w.back());
        }

        unordered_set<int> numGuard;
        int dy[4] = {-1,1,0,0};
        int dx[4] = {0,0,-1,1};
        for(const auto& g : guards){
            int y = g.front();
            int x = g.back();
            for(int d = 0; d < 4; ++d){
                int ny = y;
                int nx = x;
                while(true){
                    ny += dy[d];
                    nx += dx[d];
                    if (ny < 0 || ny >= m || nx < 0 || nx >= n) break;
                    if (guard.contains(ny*n + nx) || wall.contains(ny*n + nx)) break;
                    numGuard.insert(ny*n+nx);
                }
            }
        }

        return m*n - (guard.size() + walls.size() + numGuard.size());
    }
    
};