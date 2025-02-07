class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int dc = 0;
        unordered_map<int,int> ballColor, colorNum;
        vector<int> ans;
        for(auto q : queries){
            int b = q[0];
            int c = q[1];

            if (ballColor.find(b) == ballColor.end()){
                ballColor[b] = c;
                colorNum[c]++;
                if(colorNum[c] == 1){
                    dc++;
                }
            }
            else{
                colorNum[ballColor[b]]--;
                if(colorNum[ballColor[b]] == 0){
                    dc--;
                }
                ballColor[b] = c;
                colorNum[c]++;
                if(colorNum[c] == 1){
                    dc++;
                }
            }
            ans.push_back(dc);
        }
        return ans;
    }
};