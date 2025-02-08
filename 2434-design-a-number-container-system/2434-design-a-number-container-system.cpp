class NumberContainers {
public:
    NumberContainers() {
    }

    void change(int index, int number) {
        auto it = indexToNumber.find(index);
        if(it != indexToNumber.end()){
            numberToIndices[it->second].erase(index);
        }
        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }
    
    int find(int number) {
        auto begin = numberToIndices[number].begin();
        return begin == numberToIndices[number].end() ? -1 : *begin;
    }

private:
    unordered_map<int, set<int>> numberToIndices;
    unordered_map<int, int> indexToNumber;

};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */


