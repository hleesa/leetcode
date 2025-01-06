class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> indices;
        for(int i = 0 ; i < boxes.size(); ++i){
            if(boxes[i] == '1'){
                indices.push_back(i);
            }
        }

        vector<int> ans;
        for(int i = 0; i < boxes.size(); ++i){
            int numOp = 0;
            for(int index : indices){
                if (index == i) continue;
                numOp += abs(index - i);
            }
            ans.push_back(numOp);
        }
        
        return ans;
    }
};