class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> chToNum(26, 0);
        for(auto ch : s){
            chToNum[ch-'a']++;
        }
        vector<int> ans;
        map<int, int> cur;
        for(auto ch : s){
            cur[ch-'a']++;
            bool split = true;
            for(auto it : cur){
                if(it.second < chToNum[it.first]){
                    split = false;
                    break;
                }
            }
            if (split){
                int size = 0;
                for(auto it : cur){
                    size += it.second;
                }
                ans.push_back(size);
                cur.clear();
            }
        }
        return ans;
    }
};
