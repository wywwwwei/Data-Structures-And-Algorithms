/**
 * 705. 设计哈希集合
 * link：https://leetcode-cn.com/problems/design-hashset/
 */

class MyHashSet
{
    vector<list<int>> store;

    static const int base = 769; // prime
    static int hash(int key) { return key % base; }

public:
    /** Initialize your data structure here. */
    MyHashSet() : store(base) {}

    void add(int key)
    {
        int pos = hash(key);

        for (auto it = store[pos].begin(); it != store[pos].end(); it++)
            if ((*it) == key)
                return;

        store[pos].emplace_front(key);
    }

    void remove(int key)
    {
        int pos = hash(key);

        for (auto it = store[pos].begin(); it != store[pos].end(); it++)
            if ((*it) == key)
            {
                store[pos].erase(it);
                break;
            }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        int pos = hash(key);

        for (auto it = store[pos].begin(); it != store[pos].end(); it++)
            if ((*it) == key)
                return true;

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */