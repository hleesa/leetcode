class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i < nums.size(); ++i){
            pq.push({nums[i],i });
        }
        for(int i = 0; i < k; ++i){
            auto top = pq.top();
            pq.pop();
            top.first *= multiplier;
            pq.push(top);
        }
        while(!pq.empty()){
            nums[pq.top().second] = pq.top().first;
            pq.pop();
        }
        return nums;
    }
};