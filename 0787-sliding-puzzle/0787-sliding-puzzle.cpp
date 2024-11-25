class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        const int dy[4] = {-1,1,0,0};
        const int dx[4] = {0,0,-1,1};        
        queue<vector<vector<int>>> q;
        map<vector<vector<int>>,int> vis;

        q.push(board);
        vis[board] = 0;
        
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            auto pos = findZero(cur);

            for(int d = 0 ; d < 4; ++d){
                int ny = pos.front() + dy[d];
                int nx = pos.back() + dx[d];
                if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board.front().size()) continue;

                auto next = cur;
                swap(next[ny][nx], next[pos.front()][pos.back()]);
                auto it = vis.find(next);
                if (it == vis.end() || vis[cur] + 1 < vis[next]){
                    vis[next] = vis[cur] + 1;
                    q.push(next);
                }
            }
        }

        vector<vector<int>> target = {{1,2,3}, {4,5,0}};
        return vis.find(target) == vis.end() ? -1 : vis[target];
    }

private:
    vector<int> findZero(const vector<vector<int>>& board){
        for(int y = 0; y < board.size(); ++y){
            for(int x = 0; x < board.front().size(); ++x){
                if(board[y][x] == 0){
                    return {y,x};
                }
            }
        }
        return {-1,-1};
    }
};

