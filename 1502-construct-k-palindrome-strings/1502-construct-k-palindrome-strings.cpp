class Solution {
public:
    bool canConstruct(string s, int k) {
        int freq[26] = {0};
        for(char ch : s){
            freq[ch-'a']++;
        }

        vector<int> odd, even;
        for(int i = 0; i < 26; ++i){
            int num = freq[i];
            if(num == 0) continue;
            else if(freq[i] % 2 == 0) even.push_back(num);
            else {
                odd.push_back(1);
                if (freq[i] > 1) even.push_back(num-1);
            }
        }

        if (odd.size() > k) return false;

        int evenOdd = 0;
        for(auto e : even){
            evenOdd += e;
        }
        return odd.size() + evenOdd >= k;
    }
};
