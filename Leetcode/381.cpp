/**
 * 381. O(1) 时间插入、删除和获取随机元素 - 允许重复
 * link：https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
 */

/**
 * O(1) insert -> vector / linked list / hash table...
 * O(1) delete -> hash table
 * Duplicate elements are allowed with O(1) -> can be nums to count(nums) or nums to index(nums)
 * O(1) get random (linear probability) -> index maps to data -> vector / hash table...
 * 
 * So we use vector to store data, use nums mapping to index(nums) for delete
 */

class RandomizedCollection
{
    vector<int> store;
    unordered_map<int, unordered_set<int>> idx;

public:
    /** Initialize your data structure here. */
    RandomizedCollection()
    {
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        store.push_back(val);
        idx[val].insert(store.size() - 1);
        return idx[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        if (idx.find(val) == idx.end())
            return false;
        auto &cur = idx[val];
        int index = *cur.begin();

        store[index] = store[store.size() - 1];
        cur.erase(index);
        idx[store[index]].erase(store.size() - 1);
        if (index < store.size() - 1)
            idx[store[index]].insert(index);
        store.pop_back();

        if (cur.size() == 0)
            idx.erase(val);
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        return store[rand() % store.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    RandomizedCollection a;
    a.insert(1);
    a.insert(1);
    a.insert(2);
    a.insert(1);
    a.insert(2);
    a.insert(2);
    cout << (a.remove(1) ? 1 : 0) << " ";
    cout << (a.remove(2) ? 1 : 0) << " ";
    cout << (a.remove(2) ? 1 : 0) << " ";
    cout << (a.remove(2) ? 1 : 0) << " ";
    cout << endl;
}