class ProductOfNumbers {
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int product = 1;
        const int offset = nums.size() - 1;
        for(int i = 0; i < k; ++i){
            product *= nums[offset - i];
        }
        return product;
    }
    
private:
    vector<int> nums;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */