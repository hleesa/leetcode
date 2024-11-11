class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        getPrime();
        nums[0] = getNum(nums[0], 0);
        for(int i = 1; i < nums.size(); ++i){
            nums[i] = getNum(nums[i], nums[i-1]);
            if (nums[i] <= nums[i-1]){
                return false;
            }
        }
        return true;
    }

private:
    vector<bool> primeSieve;

    void getPrime(){
        const int n = 1001;
        primeSieve.resize(n);
        primeSieve[0] = true;
        primeSieve[1] = true;
        for(int i = 2; i < n; ++i){
            for(int j = i + i; j <= n; j += i){
                primeSieve[j] = true; 
            }
        }
    }

    int getNum(int num, int min){
        for(int i = num - 1; i >= 2; --i){
            if(!primeSieve[i]){
                if(num - i > min){
                    return num - i;
                }
            }
        }
        return num;
    }
};