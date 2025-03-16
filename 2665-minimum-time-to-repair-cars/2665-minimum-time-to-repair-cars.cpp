class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = LLONG_MAX - 1;
        long long ans = 0;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if (repairMinute(ranks, cars, mid)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    bool repairMinute(const vector<int>& ranks, int cars, long long minute){
        long long repaired = 0;
        for(auto rank : ranks){
            long long r = rank; 
            repaired += sqrt(minute / r);
        }
        return repaired >= cars;
    }
};
