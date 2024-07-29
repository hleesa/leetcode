class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int size = rating.size();
        for(int j=1; j+1<size; ++j){
            int leftLess = 0, rightGreator =0;
            int leftGreator = 0, rightLess = 0;
            
            for(int i=0; i<j; ++i){
                if(rating[i] < rating[j]) ++leftLess;
                if(rating[i] > rating[j]) ++leftGreator;
            }
            for(int k=j+1; k<size; ++k){
                if(rating[j] < rating[k]) ++rightGreator;
                if(rating[j] > rating[k]) ++rightLess;
            }
            
            ans += leftLess * rightGreator + leftGreator *rightLess;
        }
        return ans;
    }
};