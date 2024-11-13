class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        const int rEnd = image.size();
        const int cEnd = image.front().size();
        vector<vector<bool>> vis(rEnd, vector<bool>(cEnd));
        ff(image, vis, sr, sc, image[sr][sc], color, rEnd, cEnd);
        return image;
    }
private:
    const int dr[4] = {-1,1,0,0};
    const int dc[4] = {0,0,-1,1};

    void ff(vector<vector<int>>& image, vector<vector<bool>>& vis, int r, int c, int initColor, int color, int rEnd, int cEnd){
        if(r < 0 || r >= rEnd || c < 0 || c >= cEnd) return;
        else if(vis[r][c]) return;
        else if(image[r][c] != initColor) return;
        vis[r][c] = true;
        image[r][c] = color;
        for(int i = 0; i < 4; ++i){
            ff(image, vis, r+dr[i], c+dc[i], initColor, color, rEnd, cEnd);
        }
    }
};