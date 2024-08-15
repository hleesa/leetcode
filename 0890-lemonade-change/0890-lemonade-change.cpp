class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int counter[6] = {0};

        for(const auto& bill : bills){
            int i = bill/5;
            if (i == 1){
                ++counter[i];
            }
            else if (counter[1] < 1){
                return false;
            }
            else if (i == 2){
                ++counter[i];
                --counter[1];
            }
            else if (counter[2] > 0){ // i == 4
                ++counter[i];
                --counter[2];
                --counter[1];
            }
            else if (counter[1] > 2){ // i == 4
                ++counter[i];
                counter[1] -= 3;
            }
            else{
                return false;
            }
        }

        return true;
    }
};