class Solution {
public:
    bool isHappy(int n) {
        int num = n;
        set<int> vis;
        vis.insert(n);
        while(num != 1){
            int digitSquareSum = 0;
            while(num != 0){
                int digit = num % 10;
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
