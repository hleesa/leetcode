class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m < 3 || n < 3) return 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    minHeap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        int trappedWater = 0;
        int minHeight = 0;

        while (!minHeap.empty()) {
            auto [h, cell] = minHeap.top(); minHeap.pop();
            int y = cell.first, x = cell.second;

            minHeight = max(minHeight, h);

            for (auto& d : dirs) {
                int ny = y + d[0], nx = x + d[1];

                if (ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx]) continue;
                visited[ny][nx] = true;

                if (heightMap[ny][nx] < minHeight) {
                    trappedWater += minHeight - heightMap[ny][nx];
                }

                minHeap.push({heightMap[ny][nx], {ny, nx}});
            }
        }

        return trappedWater;
    }
};
