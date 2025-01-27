/*
    Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and 
    Q denotes the number of queries. Query can be of two types:

    PUT x y: sets the value of the key x with value y
    GET x: gets the key of x if present else returns -1.
    The LRUCache class has two methods get() and put() which are defined as follows.

    get(key): returns the value of the key if it already exists in the cache otherwise returns -1.
    put(key, value): if the key is already present, update its value. If not present, add the key-value 
    pair to the cache. If the cache reaches its capacity it should remove the least recently used item 
    before inserting the new item.
    In the constructor of the class the capacity of the cache should be initialized.
*/

class LRUCache {
private:
    int capacity;
    std::list<std::pair<int, int>> cacheList; // Stores key-value pairs in order of use
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap; // Maps keys to iterators in the list

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) {
            return -1; // Key not found
        }

        // Move the accessed key-value pair to the front of the list
        cacheList.splice(cacheList.begin(), cacheList, it->second);

        return it->second->second; // Return the value
    }

    void put(int key, int value) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            // Key already exists, update its value and move it to the front
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            it->second->second = value;
            return;
        }

        // If cache is full, remove the least recently used item
        if (cacheMap.size() == capacity) {
            int lruKey = cacheList.back().first;
            cacheMap.erase(lruKey);
            cacheList.pop_back();
        }

        // Add the new key-value pair to the front of the list and update the map
        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
    }
};