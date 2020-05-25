/**
 * 146. LRU缓存机制
 * link：https://leetcode-cn.com/problems/lru-cache/
 */

/**
 * How to consider which data structure to use:
 * get() -> O(1) include judging if key exists -> hash -> unordered_map
 * get() / put() -> O(1) include popping or updating the least recently used
 *               -> poping -> sequence structure
 *               -> updating -> move -> list            -> doubly linked list
 * 
 * How to use together: unordered_map (key -> position in doubly linked list)  doubly linked list (key and value)
 */

class LRUCache
{
    struct ListNode
    {
        int key;
        int value;
        ListNode *prev;
        ListNode *next;
        ListNode(int key_, int value_, ListNode *prev_ = nullptr, ListNode *next_ = nullptr)
        {
            this->key = key_;
            this->value = value_;
            this->prev = prev_;
            this->next = next_;
        }
    };

    struct DuLinkedList
    {
        void moveToHead(ListNode *cur)
        {
            //Remove the cur node from the linked list (the node may not be in the linked list)
            if (cur->prev)
                cur->prev->next = cur->next;
            else if (cur == head)
                head = cur->next;

            if (cur->next)
                cur->next->prev = cur->prev;
            else if (cur == tail)
                tail = cur->prev;

            //Insert the cur node from the head
            cur->next = head;
            cur->prev = nullptr;

            if (head)
                head->prev = cur;
            head = cur;
            if (tail == nullptr)
                tail = cur;
        }

        ListNode *pop_back()
        {
            ListNode *res = tail;
            if (tail)
            {
                tail = tail->prev;
                if (tail)
                    tail->next = nullptr;
                else
                    head = tail;
            }
            return res;
        }

    private:
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
    };

    unordered_map<int, ListNode *> store;
    DuLinkedList cache;
    int size;
    int cap;

public:
    LRUCache(int capacity)
    {
        size = 0;
        cap = capacity;
    }

    int get(int key)
    {
        if (this->store.find(key) != this->store.end())
        {
            ListNode *res = this->store[key];
            cache.moveToHead(res);
            return res->value;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (this->store.find(key) != this->store.end())
        {
            ListNode *res = this->store[key];
            res->value = value;
            cache.moveToHead(res);
        }
        else
        {
            if (this->size >= this->cap)
            {
                ListNode *tail = cache.pop_back();
                this->store.erase(tail->key);
                delete tail;
                this->size--;
            }
            ListNode *val = new ListNode(key, value);
            cache.moveToHead(val);
            this->store[key] = val;
            this->size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
