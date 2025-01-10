class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        const int alphaLen = 26;
        vector<int> freq(26);
        for(const char& task : tasks){
            freq[task-'A']++;
        }

        priority_queue<int> pq;
        for(int i = 0; i < alphaLen; ++i){
            if(freq[i] > 0){
                pq.push(freq[i]);
            }
        }

        int time = 0;
        while(!pq.empty()){
            int cycle = n + 1;
            int task = 0;
            vector<int> saved;
            while(cycle-- && !pq.empty()){
                if(pq.top() > 1){
                    saved.push_back(pq.top() - 1);
                }
                pq.pop();
                ++task;
            }
            for(auto t : saved){
                pq.push(t);
            }
            time += pq.empty() ? task : n + 1;
        }

        return time;
    }
};