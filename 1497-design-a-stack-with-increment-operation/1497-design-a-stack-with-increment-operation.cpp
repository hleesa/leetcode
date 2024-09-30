class CustomStack {
public:
    CustomStack(int maxSize) {
        capacity = maxSize;
        data = vector<int>(maxSize);
        size = 0;
    }
    
    void push(int x) {
        if (size == capacity){
            return;
        }
        data[size++] = x;
    }
    
    int pop() {
        if (size == 0){
            return -1;
        }
        return data[--size];
    }
    
    void increment(int k, int val) {
        int end = min(k, size);
        for(int i = 0; i < end; ++i){
            data[i] += val;
        }
    }
private:
    vector<int> data;
    int size;
    int capacity;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */