class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int num : nums){
            pq.push(num);
        }

        long long score = 0;
        while(k--){
            int top = pq.top();
            score += top;
            pq.pop();
            pq.push(ceil(top / 3.0));
        }

        return score;
    }
};