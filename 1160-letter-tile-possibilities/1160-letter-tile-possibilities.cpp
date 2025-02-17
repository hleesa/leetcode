class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for(char ch : tiles){
            freq[ch-'A']++;
        }
        return numTileHelper(freq);
    }

private:
    int numTileHelper(vector<int>& freq){
        int ret = 0;
        for(int i = 0; i < 26; ++i){
            if(freq[i] == 0) continue;
            ++ret;
            freq[i]--;
            ret += numTileHelper(freq);
            freq[i]++;
        }
        return ret;
    }
};