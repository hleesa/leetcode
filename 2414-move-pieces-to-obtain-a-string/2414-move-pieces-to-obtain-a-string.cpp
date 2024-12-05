class Solution {
public:
    bool canChange(string start, string target) {
        const int n = start.length();
        int si = 0, ti = 0;
        while(si < n || ti < n){
            while(start[si] == '_') ++si;
            while(target[ti] == '_') ++ti;
            if (start[si] != target[ti]) return false;
            else if (si < ti && start[si] == 'L') return false;
            else if (ti < si && start[si] == 'R') return false;
            ++si;
            ++ti;
        }
        return true;
    }
};
