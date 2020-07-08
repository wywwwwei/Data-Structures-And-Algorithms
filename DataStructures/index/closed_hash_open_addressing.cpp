#include <iostream>

using namespace std;

#define PRIME 3

struct HashNode
{
    int key;
    int value;
    HashNode(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class HashTable
{
    int capacity;
    HashNode **buckets;

    int hashFunction(int key)
    {
        return (key % this->capacity);
    }

    //Just for testing, not ensure availability
    int hash2Function(int key)
    {
        return PRIME - (key % PRIME);
    }

    int hashAndProbing(int key)
    {
        int index = hashFunction(key);
        if (this->probingType == ProbingType::Linear)
            return linearProbing(index, key);
        else if (this->probingType == ProbingType::Quadratic)
            return quadraticProbing(index, key);
        else
            return doubleHashing(index, key);
    }

    int linearProbing(int index, int &key)
    {
        while (this->buckets[index] != nullptr && this->buckets[index]->key != key)
            index = (index + 1) % this->capacity;
        return index;
    }

    int quadraticProbing(int index, int &key)
    {
        int newIndex = index;
        int count = 1;
        while (this->buckets[newIndex] != nullptr && this->buckets[newIndex]->key != key)
        {
            newIndex = (index + count * count) % this->capacity;
            count++;
        }
        return newIndex;
    }

    int doubleHashing(int index, int &key)
    {
        int h2 = hash2Function(key);
        while (this->buckets[index] != nullptr && this->buckets[index]->key != key)
            index = (index + h2) % this->capacity;
        return index;
    }

public:
    enum ProbingType
    {
        Linear,
        Quadratic,
        DoubleHash
    };
    ProbingType probingType;

    HashTable(int capacity, ProbingType probingType)
    {
        this->capacity = capacity;
        this->buckets = new HashNode *[capacity];
        for (int i = 0; i < capacity; i++)
            this->buckets[i] = nullptr;
        this->probingType = probingType;
    }

    ~HashTable()
    {
        for (int i = 0; i < this->capacity; i++)
            if (this->buckets[i] != nullptr)
                delete this->buckets[i];
    }

    void insert(int key, int data)
    {
        int index = hashAndProbing(key);
        HashNode *newNode = new HashNode(key, data);
        this->buckets[index] = newNode;
    }

    int get(int key)
    {
        int index = hashAndProbing(key);
        return this->buckets[index]->value;
    }

    void display()
    {
        for (int i = 0; i < this->capacity; i++)
        {
            cout << "Key " << i << ": ";
            HashNode *tmp = this->buckets[i];
            if (tmp)
                cout << tmp->key << " -> " << tmp->value << endl;
            else
                cout << "NULL" << endl;
        }
        cout << endl;
    }
};

void test()
{
    HashTable test(5, HashTable::ProbingType::Linear);
    test.insert(1, 1);
    test.insert(6, 2);
    test.insert(11, 3);
    test.insert(2, 4);
    test.insert(3, 5);
    test.display();
    HashTable test2(5, HashTable::ProbingType::Quadratic);
    test2.insert(1, 1);
    test2.insert(6, 2);
    test2.insert(11, 3);
    test2.insert(2, 4);
    test2.insert(3, 5);
    test2.display();
    HashTable test3(5, HashTable::ProbingType::DoubleHash);
    test3.insert(1, 1);
    test3.insert(6, 2);
    test3.insert(11, 3);
    test3.insert(2, 4);
    test3.insert(3, 5);
    test3.display();
}

int main()
{
    test();
}