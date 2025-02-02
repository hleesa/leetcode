class Solution {
public:
    bool check(vector<int>& nums) {
        deque<int> num(nums.begin(), nums.end());
        deque<int> sorted = num;
        sort(sorted.begin(), sorted.end());
        for(int i = 0; i < num.size(); ++i){
            if(num == sorted){
                return true;
            }
            num.push_back(num.front());
            num.pop_front();
        }
        return false;
    }
};