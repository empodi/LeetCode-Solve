#define LEN 1000001

class MyHashMap {
public:
    int hashMap[LEN];
    
    MyHashMap() {
        
        for (int i = 0; i < LEN; i++) {
            hashMap[i] = -1;
        }
    }
    
    void put(int key, int value) {
        
        hashMap[key] = value;
    }
    
    int get(int key) {
        
        return hashMap[key];
    }
    
    void remove(int key) {
        
        hashMap[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */