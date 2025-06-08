// key1, key2, key3, ..., key10
// get(key3)
// key1, key2, ..., key10, key3
// put(key2)
// key1, ..., key10, key3, key2'
// put(key11) /* revmove lru-->(key1) */ 
// ..., key10, key3, key11 

class LRUCache {                                        //          list.begin(), ..., list.end() - 1 , list.end()
    list<int> List;                                     // lru list (lru key,     ..., recently used key)
    unordered_map<int, list<int>::iterator> key2iter;   // key2iter (for O(1) remove)
    unordered_map<int, int> key2val;                    // key2val (for O(1) get)
    int cap;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (key2val.find(key) == key2val.end())
            return -1;
        // move key to list.end() - 1
        auto iter = key2iter[key];
        List.erase(iter);
        List.push_back(key);
        // update key2iter
        key2iter[key] = --List.end();
        // return val
        return key2val[key];
    }
    
    void put(int key, int value) {
        // if found, modify the value to the key
        // and update the key iterator pos (what get(key) does)
        if (get(key) != -1) {
            key2val[key] = value;
            return;
        }
        // else if capacity reached, remove lru and add new key
        if (List.size() == cap) {    
            int keyDel = List.front();
            List.erase(List.begin());
            key2iter.erase(keyDel);
            key2val.erase(keyDel);
        }

        // add key, value
        List.push_back(key);
        key2iter[key] = --List.end();
        key2val[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



// Using self-defined data structure might give faster execution time

/* TODO */
