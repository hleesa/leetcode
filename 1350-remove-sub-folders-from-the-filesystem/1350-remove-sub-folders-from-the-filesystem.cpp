class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        string lastFolder;
        for(const string& f : folder){
            if(lastFolder.empty() || f.find(lastFolder + '/') != 0){
                result.push_back(f);
                lastFolder = f;
            }
        }
        return result;
    }
};