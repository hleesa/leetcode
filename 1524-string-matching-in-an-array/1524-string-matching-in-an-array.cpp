class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        const int n = words.size();
        vector<string> ans;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j || words[i].length() > words[j].length()) continue;
                if (words[j].find(words[i]) != std::string::npos){
                    ans.push_back(words[i]);
                }
            }
        }
        // sort(ans.begin(), ans.end());
        ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};