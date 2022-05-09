class MyHashSet {
public:
    bool array[1000001];
    
    MyHashSet() {
        
        memset(array, false, sizeof(array));
    }
    
    void add(int key) {
        array[key] = true;
    }
    
    void remove(int key) {
        array[key] = false;
    }
    
    bool contains(int key) {
        return array[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */