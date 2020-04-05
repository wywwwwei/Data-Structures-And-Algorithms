/**
 * 460. LFU缓存
 * link：https://leetcode-cn.com/problems/lfu-cache/
 */

/**
 *  get(key) -> O(1) -> hashmap -> unordered_map key_map
 *  get(least frequency) -> O(1) -> hashmap -> unordered_map freq_map
 *  delete(least frequency) -> O(1) -> any sequence container with hash -> freq_map's template is <int,List/Array...>
 */

class LFUCache
{
private:
    struct Node
    {
        int freq;
        int key;
        int val;
        Node(int _freq, int _key, int _val) : freq(_freq), key(_key), val(_val) {}
    };

    int capacity;
    int minFreq;
    unordered_map<int, list<Node *>::iterator> key_map;
    unordered_map<int, list<Node *>> freq_map;

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (this->capacity == 0)
            return -1;

        auto iter = key_map.find(key);
        if (iter == key_map.end())
            return -1;

        int val = (*iter->second)->val;
        updateFreq(iter->second);
        return val;
    }

    void put(int key, int value)
    {
        if (this->capacity == 0)
            return;

        auto iter = key_map.find(key);
        if (iter == key_map.end())
        {
            if (key_map.size() == capacity)
            {
                deleteKey();
            }

            Node *create = new Node(1, key, value);
            this->minFreq = 1;

            auto &freq_list = this->freq_map[1];
            freq_list.push_front(create);
            this->key_map[key] = freq_list.begin();
        }
        else
        {
            (*iter->second)->val = value;
            updateFreq(iter->second);
        }
    }

    void updateFreq(list<Node *>::iterator &iter)
    {
        Node *temp = *iter;
        int freq = temp->freq;

        auto &freq_list = this->freq_map[freq];
        freq_list.erase(iter);
        if (freq_list.size() == 0)
        {
            freq_map.erase(freq);
            if (this->minFreq == freq)
                this->minFreq += 1;
        }

        temp->freq++;
        auto &freq_list2 = freq_map[freq + 1];
        freq_list2.push_front(temp);
        key_map[temp->key] = freq_list2.begin();
    }

    void deleteKey()
    {
        auto &freq_list = this->freq_map[this->minFreq];
        Node *temp = freq_list.back();
        freq_list.pop_back();

        if (freq_list.size() == 0)
        {
            freq_map.erase(temp->freq);
        }
        key_map.erase(temp->key);
        delete temp;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */