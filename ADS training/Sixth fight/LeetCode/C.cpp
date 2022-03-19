// link: https://leetcode.com/problems/design-hashset/

class MyHashSet {
    bool values[1000001];
public:
    MyHashSet() {
        for (int i = 0; i < 1000001; i++) {
            values[i] = false;    
        }
    }
    
    void add(int key) {
        values[key] = true;
    }
    
    void remove(int key) {
        values[key] = false;
    }
    
    bool contains(int key) {
        return values[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */