class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        string ans;
        
        while(!pq.empty()){
            auto first = pq.top(); pq.pop();

            if(ans.size() >= 2 && ans[ans.size() - 1] == first.second && ans[ans.size() - 2] == first.second){
                if(pq.empty()){
                    break;
                }

                auto second = pq.top(); pq.pop();
                ans += second.second;
                --second.first;

                if(second.first > 0){
                    pq.push(second);
                }
                pq.push(first);
            }
            else{
                ans += first.second;
                --first.first;

                if(first.first > 0){
                    pq.push(first);
                }
            }
        }

        return ans;
    }
};