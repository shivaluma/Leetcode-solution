class SmallestInfiniteSet {
public:

    int min_num = 1;
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
    std::unordered_set<int> nums;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if (heap.size()) {
            int smallest = heap.top();
            heap.pop();
            nums.erase(smallest);
            return smallest;
        }

        min_num += 1;
        return min_num - 1;
    }
    
    void addBack(int num) {
        if (num < min_num && nums.find(num) == nums.end()) {
            heap.push(num);
            nums.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */