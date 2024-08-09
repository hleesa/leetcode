class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int size = 2;
        int numMagicSquare = 0;
        for(int y = 0; y + size < grid.size(); ++y){
            for(int x = 0; x + size < grid[y].size(); ++x){
                if (magicSquare(grid, y, x)){
                    ++numMagicSquare;
                }
            }
        }
        return numMagicSquare;
    }

private:
    const int N = 3;

    bool magicSquare(const vector<vector<int>>& grid, int y, int x){
        int numCounter[10] = {0};
        for(int dy=0; dy < N; ++dy){
            for(int dx = 0; dx < N; ++dx){
                const int num = grid[y+dy][x+dx];
                if (num < 1 || 9 < num) return false;
                ++numCounter[num];
                if(numCounter[num] > 1) return false;
            }
        }
        
        vector<int> sums;
        for(int i=0; i<N; ++i){
            int ySum = 0;
            int xSum = 0;
            for(int dy = 0; dy < N; ++dy){
                ySum += grid[y+dy][x+i];
            }
            for(int dx = 0; dx < N; ++dx){
                xSum += grid[y+i][x+dx];
            }
            sums.push_back(ySum);
            sums.push_back(xSum);
        }
        sums.push_back(grid[y][x] + grid[y+1][x+1] + grid[y+2][x+2]);
        sums.push_back(grid[y+2][x] + grid[y+1][x+1] + grid[y][x+2]);
        for(int i=0; i+1 < sums.size(); ++i){
            if(sums[i] != sums[i+1]){
                return false;
            }
        }

        return true;
    }
};