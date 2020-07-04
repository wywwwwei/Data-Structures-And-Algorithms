#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val, ListNode *next = nullptr)
    {
        this->val = val;
        this->next = next;
    }
};

class HashTable
{
private:
    int capacity;
    ListNode **buckets;

public:
    HashTable(int capacity)
    {
        this->capacity = capacity;
        this->buckets = new ListNode *[capacity];
        for (int i = 0; i < capacity; i++)
            this->buckets[i] = nullptr;
    }

    ~HashTable()
    {
        ListNode *tmp = nullptr;
        for (int i = 0; i < capacity; i++)
            while (this->buckets[i] != nullptr)
            {
                tmp = this->buckets[i];
                this->buckets[i] = this->buckets[i]->next;
                delete tmp;
            }
        delete[] buckets;
    }

    int hashFunction(int key)
    {
        return (key % this->capacity);
    }

    void insert(int data)
    {
        int index = hashFunction(data);
        ListNode *newNode = new ListNode(data, this->buckets[index]);
        this->buckets[index] = newNode;
    }

    void remove(int data)
    {
        int index = hashFunction(data);
        ListNode *tmp = this->buckets[index];
        ListNode *tmpPrev = nullptr;
        while (tmp != nullptr)
        {
            if (tmp->val == data)
            {
                if (tmpPrev)
                    tmpPrev->next = tmp->next;
                else
                    this->buckets[index] = tmp->next;
                delete tmp;
                break;
            }
            tmpPrev = tmp;
            tmp = tmp->next;
        }
    }

    void display()
    {
        for (int i = 0; i < this->capacity; i++)
        {
            cout << "Key " << i << ": ";
            ListNode *tmp = this->buckets[i];
            while (tmp != nullptr)
            {
                cout << tmp->val << " -> ";
                tmp = tmp->next;
            }
            cout << "NULL" << endl;
        }
        cout << endl;
    }
};

void test()
{
    HashTable test(5);
    test.insert(1);
    test.insert(1);
    test.insert(6);
    test.insert(3);
    test.insert(5);
    test.display();
    test.remove(1);
    test.remove(5);
    test.display();
}

int main()
{
    test();
}