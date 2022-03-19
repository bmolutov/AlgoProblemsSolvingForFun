// link: https://leetcode.com/problems/design-hashmap/

class MyHashMap {
    int values[1000001];
public:
    MyHashMap() {
        for (int i = 0; i < 1000001; i++) {
            values[i] = -1;
        }
    }
    
    void put(int key, int value) {
        values[key] = value;
    }
    
    int get(int key) {
        return values[key];
    }
    
    void remove(int key) {
        values[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */