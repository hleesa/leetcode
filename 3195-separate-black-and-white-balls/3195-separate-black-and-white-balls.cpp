class Solution {
public:
    long long minimumSteps(string s) {
        const int n = s.length(); 
        deque<int> zeroIndices, oneIndices;
        for(int i = 0; i < n; ++i){
            if (s[i] == '0'){
                zeroIndices.push_back(i);
            }
            else{
                oneIndices.push_back(i);
            }
        }

        long long steps = 0;
        while(!oneIndices.empty() && !zeroIndices.empty() && oneIndices.front() < zeroIndices.back()){
            steps += zeroIndices.back() - oneIndices.front();
            oneIndices.pop_front();
            zeroIndices.pop_back();
        }

        return steps;
    }
};