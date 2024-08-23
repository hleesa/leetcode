class Solution {
public:
    string fractionAddition(string expression) {
        stringstream ss(expression);
        vector<vector<int>> nums;
        int lhs, rhs;
        char slash;
        int numerator = 0;
        int denominator = 1;

        while(ss >> lhs){
            ss >> slash >> rhs;
            nums.push_back({lhs,rhs});
            denominator = lcm(denominator, rhs);
        }

        for(const auto& num : nums){
            numerator += (denominator / abs(num.back())) * num.front() ;
        }

        int q = gcd(numerator, denominator);
        if (q != 0){
            numerator /= q;
            denominator /= q;
        }
        if (numerator * denominator < 0 && denominator < 0){
            numerator *= -1;
            denominator *= -1;
        }

        return to_string(numerator) + "/" + to_string(denominator);
    }

private:
    int gcd(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int lcm(int a, int b){
        return (a * b) / gcd(a,b);
    }
};