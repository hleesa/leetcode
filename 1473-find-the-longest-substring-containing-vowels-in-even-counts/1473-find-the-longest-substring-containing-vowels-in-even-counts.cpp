class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> vowelToBit {
            {'a', 1 << 0},
            {'e', 1 << 1},
            {'i', 1 << 2},
            {'o', 1 << 3},
            {'u', 1 << 4}
        };

        unordered_map<int, int> stateToIndex;
        stateToIndex[0] = -1;

        int currentState = 0;
        int maxLength = 0;

        for(int i = 0; i < s.size(); ++i){
            if(vowelToBit.find(s[i]) != vowelToBit.end()){
                currentState ^= vowelToBit[s[i]];
            }

            if(stateToIndex.find(currentState) != stateToIndex.end()){
                maxLength = max(i - stateToIndex[currentState], maxLength);
            }
            else{
                stateToIndex[currentState] = i;
            }
        }

        return maxLength;
    }
};
