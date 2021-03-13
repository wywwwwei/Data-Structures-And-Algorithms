/**
 * 706. 设计哈希映射
 * link：https://leetcode-cn.com/problems/design-hashmap/
 */

class MyHashMap
{
    vector<list<pair<int, int>>> store;

    static const int base = 769; // prime
    static int hash(int key) { return key % base; }

public:
    /** Initialize your data structure here. */
    MyHashMap() : store(base) {}

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        int pos = hash(key);

        for (auto it = store[pos].begin(); it != store[pos].end(); it++)
            if (it->first == key)
            {
                it->second = value;
                return;
            }

        store[pos].emplace_front(make_pair(key, value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        int pos = hash(key);

        for (auto it = store[pos].begin(); it != store[pos].end(); it++)
            if (it->first == key)
                return it->second;

        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        int pos = hash(key);

        for (auto it = store[pos].begin(); it != store[pos].end(); it++)
            if (it->first == key)
            {
                store[pos].erase(it);
                break;
            }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */