class Solution {
public:
    bool isHappy(int n) {
        long long num = n;
        set<long long> vis;
        vis.insert(n);
        for(int i = 0; ; ++i){
            long long digitSquareSum = 0;
            while(num != 0){
                long long digit = num % 10;
                digitSquareSum += digit * digit;
                num /= 10;
            }

            num = digitSquareSum;
            if(vis.contains(num)){
                break;
            }
            vis.insert(num);
        }

        return num == 1;
    }
};
