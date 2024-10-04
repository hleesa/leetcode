class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        const int n = skill.size();
        long long productSum = skill.front() * skill.back();
        int pairSum  = skill.front() + skill.back();
        for(int i = 1 ; 2 * i  < n; ++i){
            if(skill[i] + skill[n-1-i] == pairSum){
                productSum += skill[i] * skill[n-1-i];
            }
            else{
                return -1;
            }
        }
        return productSum;
    }
};