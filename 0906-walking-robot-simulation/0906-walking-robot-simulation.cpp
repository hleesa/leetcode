class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int,int>, bool> obstacle;
        for(const auto& obstcl : obstacles){
            obstacle[{obstcl.front(), obstcl.back()}] = true;
        }

        int ret = 0;
        vector<int> cur = {0,0,0};
        for(const auto& cmd : commands){
            if(cmd < 0){
                int dir = cur.back();
                if (cmd == -1){
                    dir = (dir + 1) % 4;
                }
                else{ // -2
                    dir = (dir + 3) % 4;
                }
                cur.back() = dir;
            }
            else {
                for(int i =0; i < cmd; ++i){
                    int nx = cur[0] + dx[cur.back()];
                    int ny = cur[1] + dy[cur.back()];
                    if (obstacle[{nx,ny}]) break;
                    cur[0] = nx;
                    cur[1] = ny;
                }
            }
            int candi = cur[0] * cur[0] + cur[1] * cur[1];
            if (candi > ret){
                ret = candi;
            }
        }

        return ret;
    }
private:
    const int dy[4] = {1, 0, -1, 0};
    const int dx[4] = {0, 1, 0, -1};
};