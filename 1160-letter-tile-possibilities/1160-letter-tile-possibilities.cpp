class Solution {
public:
    int numTilePossibilities(string tiles) {
        map<int,int> tileNum;
        for(char ch : tiles){
            tileNum[ch]++;
        }
        map<int,int> visited;
        set<string> counter;
        numHelper(tileNum, visited, counter, "", tiles.length());

        return counter.size() - 1;
    }

    void numHelper(const map<int,int>& tileNum, map<int,int>& visited, set<string>& counter, string cur, const int len){
        if (cur.length() > len) return;
        counter.insert(cur);
        for(auto [ch, num] : tileNum){
            if (visited[ch] >= num) continue;
            cur += ch;
            visited[ch]++;
            numHelper(tileNum, visited, counter, cur, len);
            visited[ch]--;
            cur.pop_back();
        }
    }
};