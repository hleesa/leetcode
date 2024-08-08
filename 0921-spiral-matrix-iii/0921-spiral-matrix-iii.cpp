class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> visited;
        Move cur(rStart, cStart, 0, 1, 0);
        cur.move(visited, rows, cols);
        return visited;
    }

private:
    class Move {
        private:

        int row;
        int col;
        int dir;
        int distance;
        int count;
        const int deltaPos[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        bool outOfMatrix(int rows, int cols){
            if (row < 0 || rows <= row ) return true;
            else if (col < 0 || cols <= col ) return true;
            return false;
        }

        vector<int> getPos(){
            return vector<int>({row,col});
        }

        public:

        Move(int row, int col, int dir, int distance, int count) : row(row), col(col),
        dir(dir), distance(distance), count(count){}

        void move(vector<vector<int>>& visited, int rows, int cols){
            while(true){
                for(int i =0; i < distance; ++i){
                    if (!outOfMatrix(rows, cols)){
                        visited.push_back(getPos());
                        if(visited.size() >= rows * cols){
                            return;
                        }
                    }
                    row += deltaPos[dir][0];
                    col += deltaPos[dir][1];
                }
                ++count;
                if(count % 2 == 0){
                    ++distance;
                }
                dir = (dir + 1 ) % 4;
            }
        }
    };
};
