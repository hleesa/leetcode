class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int size = flowerbed.size();
        for(int i = 0; i < size; ++i){
            if (flowerbed[i] == 1) continue;
            if (i > 0 && flowerbed[i-1] == 1) continue;
            if (i + 1 < size && flowerbed[i + 1] == 1) continue;
            flowerbed[i] = 1;
            ++cnt;
        }
        return cnt >= n;
    }
};