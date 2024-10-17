class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        vector<bool> sel(numStr.length());
        fill(sel.rbegin(), sel.rbegin() + min(2UL, sel.size()), true);

        int maxNumber = num;
        do{
            vector<int> indices;
            for(int i = 0; i < sel.size(); ++i){
                if(sel[i]) indices.push_back(i);
            }
            int candi = swappedNumber(numStr, indices);
            if (candi > maxNumber){
                maxNumber = candi;
            }
        } while(next_permutation(sel.begin(), sel.end()));

        return maxNumber;
    }

private:
    int swappedNumber(string num, const vector<int>& indices){
        swap(num[indices.front()], num[indices.back()]);
        return stoi(num);
    }
};