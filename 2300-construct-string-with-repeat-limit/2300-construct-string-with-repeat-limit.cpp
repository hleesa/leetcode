class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char,int> counter;
        for(const auto& c : s){
            counter[c]++;
        }
        priority_queue<char> pq;
        for(const auto& it : counter){
            pq.push(it.first);
        }
        
        string ans;
        while(!pq.empty()){
            char cur = pq.top(); pq.pop();
            char saved = 0;
            if(!ans.empty() && ans.back() == cur){
                if (pq.empty()){
                    break;
                }
                saved = cur;
                cur = pq.top();
                pq.pop();
            }
            if(saved != 0){
                ans.append(1, cur);
                counter[cur]--;
                pq.push(saved);
            }
            else{
                int len = min(repeatLimit, counter[cur]);
                ans.append(len, cur);
                counter[cur] -= len;
            }
            if (counter[cur] > 0){
                pq.push(cur);
            }
        }
        return ans;
    }
};