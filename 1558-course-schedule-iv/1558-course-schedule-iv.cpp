class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> pre(numCourses, vector<bool>(numCourses, false));
        for(auto p : prerequisites){
            pre[p.front()][p.back()] = true;
        }

        for(int k = 0; k < numCourses; ++k){
            for(int i = 0; i < numCourses; ++i){
                for(int j = 0; j < numCourses; ++j){
                    if(pre[i][k] && pre[k][j]){
                        pre[i][j] = true;
                    }
                }
            }
        }

        vector<bool> ans;
        for(auto q : queries){
            ans.push_back(pre[q.front()][q.back()]);
        }
        return ans;
    }
};