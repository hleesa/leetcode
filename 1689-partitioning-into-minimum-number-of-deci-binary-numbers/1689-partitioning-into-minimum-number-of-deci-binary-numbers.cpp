class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(int i = 0; i < n.length(); ++i){
            int digit = n[i] - '0';
            if(digit > ans){
                ans = digit;
            }
        }
        
        return ans;
    }
};