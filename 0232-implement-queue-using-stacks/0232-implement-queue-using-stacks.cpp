class MyQueue {

public:
    MyQueue() : in(stack<int>()), out(stack<int>()){
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        int top = peek();
        out.pop();
        return top;
    }
    
    int peek() {
        if (out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        int top = out.top();
        return top;
        
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }

private:
    stack<int> in, out;
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */