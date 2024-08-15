class LRUCache {
public:
    list<int> dll; // C++ STL for doubly linked list
    map<int, pair<list<int>::iterator, int>> mp; // Stores the iterator and value corresponding to each key
    
    int capacity;
   
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void makeRecentlyUsed(int key){
        dll.erase(mp[key].first); // Erase the current position in the list
        dll.push_front(key); // Insert the key at the front of the list
        mp[key].first = dll.begin(); // Update the iterator in the map
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        // If present in map -> mark it as recently used
        makeRecentlyUsed(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            // Update the value
            mp[key].second = value;
            // Mark it as recently used
            makeRecentlyUsed(key);
        } else {
            // If the cache is full, remove the least recently used item
            if(dll.size() == capacity){
                int key_to_be_deleted = dll.back(); // Get the least recently used key
                dll.pop_back(); // Remove it from the list
                mp.erase(key_to_be_deleted); // Erase the key from the map
            }

            // Insert the new key-value pair
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
