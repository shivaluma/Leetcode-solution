class MyHashSet {
public:
    vector<bool> store;
    MyHashSet() {
        store = vector<bool>(1000001, false);
    }
    
    void add(int key) {
        store[key] = true;
    }
    
    void remove(int key) {
        store[key] = false;
    }
    
    bool contains(int key) {
        return store[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */