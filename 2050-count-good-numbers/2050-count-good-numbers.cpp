
class Solution {
public:

    using ll = long long;
    const int mod = 1e9 + 7;

    int countGoodNumbers(long long n) {
        ll evens = (n+1) / 2;
        ll odds = n / 2;

        ll even = modPow(5, evens, mod);
        ll odd = modPow(4, odds, mod);
        return even * odd % mod;
    }

    ll modPow(ll base, ll exp, ll mod){
        ll result = 1;
        base %= mod;
        while(exp > 0){
            if (exp % 2 == 1) result = result * base % mod;
            base = base * base % mod;
            exp /= 2;
        }
        return result;
    }
};
