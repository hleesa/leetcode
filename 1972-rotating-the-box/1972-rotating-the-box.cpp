class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        const int yEnd = box.front().size();
        const int xEnd = box.size();
        vector<vector<char>> rbox(yEnd, vector<char>(xEnd));
        for(int y = 0; y < box.size(); ++y){
            for(int x = 0; x < box.front().size(); ++x){
                rbox[x][box.size() - 1 - y] = box[y][x];
            }
        }

        for(int y = yEnd - 1; y >= 0; --y){
            for(int x = 0; x < xEnd; ++x){
                if(rbox[y][x] != '#') continue;
                int ny = y;
                while(ny + 1 < yEnd && rbox[ny+1][x] == '.'){
                    ++ny;
                }
                swap(rbox[ny][x], rbox[y][x]);
            }
        }
        return rbox;
    }
};