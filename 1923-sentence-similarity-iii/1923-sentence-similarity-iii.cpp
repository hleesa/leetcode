class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> sen1 = parse(sentence1);
        vector<string> sen2 = parse(sentence2);
        if(sen1.size() < sen2.size()){
            swap(sen1, sen2);
        }

        int i = 0, j = 0;
        int n1 = sen1.size(), n2 = sen2.size();

        while(i < n2 && sen1[i] == sen2[i]){
            ++i;
        }
        
        while(j < n2 && sen1[n1 -1 -j] == sen2[n2 -1 -j]){
            ++j;
        }

        return i + j >= n2;
    }
private:
    vector<string> parse(string str){
        stringstream ss(str);
        vector<string> ret;
        string token;
        while(ss >> token){
            ret.push_back(token);
        }
        return ret;
    }
};