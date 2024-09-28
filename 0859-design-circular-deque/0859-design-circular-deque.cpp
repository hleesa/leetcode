class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        data = vector<int>(k);
        front_idx = 0;
        back_idx = 1;
        size = 0;
        capacity = k;
    }
    
    bool insertFront(int value) {
        if (isFull()){
            return false;
        }
        data[front_idx] = value;
        front_idx = (front_idx - 1 + data.size() ) % data.size();
        ++size;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()){
            return false;
        }
        data[back_idx] = value;
        back_idx = (back_idx + 1 ) % data.size();
        ++size;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()){
            return false;
        }
        front_idx = (front_idx + 1) % data.size();
        --size;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()){
            return false;
        }
        back_idx = (back_idx - 1 + data.size()) % data.size();
        --size;
        return true;
    }
    
    int getFront() {
        if (isEmpty()){
            return -1;
        }
        return data[(front_idx + 1) % data.size()];
    }
    
    int getRear() {
        if (isEmpty()){
            return -1;
        }
        return data[(back_idx - 1 + data.size()) % data.size()];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }

private:
    vector<int> data;
    int front_idx;
    int back_idx;
    int size;
    int capacity;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */