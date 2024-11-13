class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> vis(image.size(), vector<bool>(image.front().size()));
        floodFillHelper(image, vis, sr, sc, image[sr][sc], color);
        return image;
    }
private:
    const int dr[4] = {-1,1,0,0};
    const int dc[4] = {0,0,-1,1};

    void floodFillHelper(vector<vector<int>>& image, vector<vector<bool>>& vis, int r, int c, int initColor, int color){
        if(r < 0 || r >= image.size() || c < 0 || c >= image.front().size()) return;
        else if(vis[r][c]) return;
        else if(image[r][c] != initColor) return;
        vis[r][c] = true;
        image[r][c] = color;
        for(int i = 0; i < 4; ++i){
            floodFillHelper(image, vis, r+dr[i], c+dc[i], initColor, color);
        }
    }
};