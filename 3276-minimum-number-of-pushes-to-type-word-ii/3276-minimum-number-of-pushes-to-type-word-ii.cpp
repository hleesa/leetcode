class Solution {
public:
    int minimumPushes(string word) {
        int counter[26] = {0};
        for(auto w : word){
            ++counter[w-'a'];
        }
        priority_queue<int> pq;
        for(int i = 0; i < 26; ++i){
            if(counter[i] == 0) continue;
            pq.push(counter[i]);
        }
        int ans = 0, i = 8;
        while(!pq.empty()){
            ans += pq.top() * (i / 8);
            pq.pop();
            ++i;
        }
        return ans;
    }
};