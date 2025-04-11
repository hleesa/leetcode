class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ret = 0;
        for(int x = max(low, 10); x <= high; ++x){
            deque<int> dq;
            int num = x;
            while(num){
                dq.push_back(num%10);
                num /= 10;
            }
            if (dq.size() % 2 != 0) continue;
            const int n = dq.size() / 2;
            int fSum = accumulate(dq.begin(), dq.begin() + n, 0);
            int lSum = accumulate(dq.begin() + dq.size() - n,  dq.end(), 0);
            if (fSum == lSum) {
                ++ret;
            }
        }
        return ret;
    }
};