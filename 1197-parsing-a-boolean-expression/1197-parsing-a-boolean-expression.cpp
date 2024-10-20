class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> ops;
        stack<vector<bool>> values;

        for(char c : expression){
            if (c == 't' || c == 'f'){
                values.top().push_back(c == 't');
            }
            else if (c == '!' || c == '&' || c == '|'){
                ops.push(c);
                values.push({});
            }
            else if (c == '('){
                continue;
            }
            else if (c == ')'){
                char op = ops.top();
                ops.pop();

                vector<bool> vals = values.top();
                values.pop();

                bool result;
                if(op == '!'){
                    result = !vals.front();
                }
                else if (op == '&'){
                    result = true;
                    for(bool val : vals){
                        result = result && val;
                    }
                }
                else if (op == '|'){
                    result = false;
                    for(bool val : vals){
                        result = result || val;
                    }
                }

                if (!values.empty()){
                    values.top().push_back(result);
                }
                else{
                    values.push({result});
                }
            }
        }
        return values.top().front();
    }
};