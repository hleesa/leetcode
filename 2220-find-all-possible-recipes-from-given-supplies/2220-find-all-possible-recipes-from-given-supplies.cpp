class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> sup(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;

        for (int i = 0; i < recipes.size(); ++i) {
            indegree[recipes[i]] = ingredients[i].size();
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
            }
        }

        queue<string> q;
        for (const string& s : supplies) q.push(s);

        vector<string> ans;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            if (indegree.find(cur) != indegree.end() && indegree[cur] == 0) { 
                ans.push_back(cur); 
            }

            for (const string& recipe : graph[cur]) {
                if (--indegree[recipe] == 0) {
                    q.push(recipe);
                }
            }
        }

        return ans;
    }
};
