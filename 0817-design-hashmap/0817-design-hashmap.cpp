class MyHashMap {
public:
    MyHashMap() {
        memo = vector<int>(1000001, -1);
    }
    
    void put(int key, int value) {
        memo[key] = value;
    }
    
    int get(int key) {
        return memo[key];
    }
    
    void remove(int key) {
        memo[key] = -1;
    }

private:
    vector<int> memo;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */