class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniors = 0;
        for(const auto& detail : details){
            if (stoi(detail.substr(11,2)) > 60){
                ++seniors;
            }
        }
        return seniors;
    }
};