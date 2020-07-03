#include <iostream>
#include <cstring>

using namespace std;

#define MIN_KEY(x) ((x + 1) / 2 - 1)

//External Searching
template <class Record, int order>
struct BTreeNode
{
    Record values[order - 1];
    BTreeNode<Record, order> *children[order];
    int count;
    bool isLeaf;
    BTreeNode(bool isLeaf)
    {
        this->count = 0;
        for (int i = 0; i < order; i++)
            children[i] = nullptr;
        this->isLeaf = isLeaf;
    }

    bool isFull()
    {
        return order - 1 == this->count;
    }

    //Check whether the key is at the current node and
    //indicate its position in values or children
    bool indexInNode(Record &val, int &position)
    {
        position = 0;
        while (position < this->count && this->values[position] < val)
            position++;
        if (position < this->count && this->values[position] == val)
            return true;
        return false;
    }

    // Insert

    // Insert value into node, if the value already exists, return
    void pushIn(Record &val, BTreeNode<Record, order> *branch)
    {
        int insertPos;
        if (indexInNode(val, insertPos))
            return;
        memmove(&this->values[insertPos + 1], &this->values[insertPos], sizeof(Record) * (this->count - insertPos));
        this->values[insertPos] = val;
        if (branch)
            this->children[insertPos + 1] = branch;
        this->count++;
    }

    // Insert value into node, if the value already exists, return
    void pushIn(Record &val, BTreeNode<Record, order> *branch, int insertPos)
    {
        memmove(&this->values[insertPos + 1], &this->values[insertPos], sizeof(Record) * (this->count - insertPos));
        this->values[insertPos] = val;
        if (branch)
            this->children[insertPos + 1] = branch;
        this->count++;
    }

    void splitNode(Record &val, BTreeNode<Record, order> *&newBranch, int &newVal)
    {
        int insertPos;
        if (indexInNode(val, insertPos))
            return;

        BTreeNode<Record, order> *extraBranch = newBranch;
        newBranch = new BTreeNode<Record, order>(this->isLeaf);
        int mid = order / 2;
        if (insertPos <= mid)
        {
            memmove(newBranch->values, &this->values[mid], sizeof(Record) * (this->count - mid));
            memmove(&newBranch->children[1], &this->children[mid + 1], sizeof(Record) * (this->count - mid));
            this->count = mid;
            newBranch->count = order - 1 - mid;
            this->pushIn(val, extraBranch, insertPos);
        }
        else
        {
            mid++;
            memmove(newBranch->values, &this->values[mid], sizeof(Record) * (this->count - mid));
            memmove(&newBranch->children[1], &this->children[mid + 1], sizeof(Record) * (this->count - mid));
            this->count = mid;
            newBranch->count = order - 1 - mid;
            newBranch->pushIn(val, extraBranch, insertPos - mid);
        }
        newVal = this->values[this->count - 1];
        newBranch->children[0] = this->children[this->count];
        this->count--;
    }

    //Remove
    void removeFromLeaf(Record &val, int position)
    {
        if (!this->isLeaf)
            return;
        memmove(&this->values[position], &this->values[position + 1], sizeof(Record) * (this->count - position - 1));
        this->count--;
    }

    int getSuccessor(int position)
    {
        BTreeNode<Record, order> *searchNode = this->children[position + 1];
        while (!searchNode->isLeaf)
            searchNode = searchNode->children[0];
        return searchNode->values[0];
    }

    void borrowFromLeft(int position)
    {
        BTreeNode<Record, order> *child = this->children[position];
        BTreeNode<Record, order> *sibling = this->children[position - 1];

        memmove(&child->values[1], child->values, sizeof(Record) * child->count);
        memmove(&child->children[1], child->children, sizeof(Record) * (child->count + 1));

        child->values[0] = this->values[position - 1];
        child->children[0] = sibling->children[sibling->count];
        this->values[position - 1] = sibling->values[sibling->count - 1];

        sibling->count--;
        child->count++;
    }

    void borrowFromRight(int position)
    {
        BTreeNode<Record, order> *child = this->children[position];
        BTreeNode<Record, order> *sibling = this->children[position + 1];

        child->values[child->count] = this->values[position];
        child->children[child->count + 1] = sibling->children[0];
        this->values[position] = sibling->values[0];

        memmove(sibling->values, &sibling->values[1], sizeof(Record) * (sibling->count - 1));
        memmove(sibling->children, &sibling->children[1], sizeof(Record) * sibling->count);

        sibling->count--;
        child->count++;
    }

    void merge(int position)
    {
        BTreeNode<Record, order> *child = this->children[position];
        BTreeNode<Record, order> *sibling = this->children[position + 1];

        child->values[child->count] = this->values[position];
        memmove(&child->values[child->count + 1], sibling->values, sizeof(Record) * sibling->count);
        memmove(&child->children[child->count + 1], sibling->children, sizeof(Record) * (sibling->count + 1));

        child->count += 1 + sibling->count;
        delete sibling;

        memmove(&this->values[position], &this->values[position + 1], sizeof(Record) * (this->count - position - 1));
        memmove(&this->children[position + 1], &this->children[position + 2], sizeof(Record) * (this->count - position - 1));
        this->count--;
    }
};

template <class Record, int order>
class BTree
{
    BTreeNode<Record, order> *root;

    // Starting from the leaf node,
    // inserting the key leads to two results
    // 1. The node is not full -> insert directly  2. The node is full -> split and insert

    // Left Node : insert key and nullptr
    // Internal Node: insert the new key and node caused by its children's spliting
    void insert(BTreeNode<Record, order> *cur, Record &val, BTreeNode<Record, order> *&newBranch, Record &newVal)
    {
        if (cur->isLeaf)
        {
            if (cur->isFull())
                cur->splitNode(val, newBranch, newVal);
            else
                cur->pushIn(val, newBranch);
            return;
        }
        int insertPos;
        if (cur->indexInNode(val, insertPos))
            return;
        insert(cur->children[insertPos], val, newBranch, newVal);
        if (newBranch != nullptr)
        {
            if (cur->isFull())
                cur->splitNode(newVal, newBranch, newVal);
            else
            {
                cur->pushIn(newVal, newBranch);
                newBranch = nullptr;
            }
        }
    }

    //In Leaf Node: remove directly and start rebalancing
    //In Internal Node: Replace it by successor and remove successor from leaf node, start rebalancing from leaf node
    void remove(BTreeNode<Record, order> *cur, Record &val)
    {
        int position;
        if (cur->indexInNode(val, position))
        {
            if (cur->isLeaf)
            {
                cur->removeFromLeaf(val, position);
            }
            else
            {
                int successor = cur->getSuccessor(position);
                cur->values[position] = successor;
                remove(cur->children[position + 1], successor);
                rebalance(cur);
            }
            return;
        }
        if (cur->isLeaf)
            return;
        remove(cur->children[position], val);
        rebalance(cur);
    }

    void rebalance(BTreeNode<Record, order> *cur)
    {
        for (int i = 0; i <= cur->count; i++)
        {
            if (cur->children[i]->count < MIN_KEY(order))
            {
                if (i > 0 && cur->children[i - 1]->count > MIN_KEY(order))
                    cur->borrowFromLeft(i);
                else if (i <= cur->count && cur->children[i + 1]->count > MIN_KEY(order))
                    cur->borrowFromRight(i);
                else
                {
                    if (i != cur->count)
                        cur->merge(i);
                    else
                        cur->merge(i - 1);
                }
            }
        }
    }

    void traverse(BTreeNode<Record, order> *cur)
    {
        if (cur == nullptr)
            return;

        for (int i = 0; i < cur->count; i++)
        {
            if (!cur->isLeaf)
                traverse(cur->children[i]);
            cout << cur->values[i] << " ";
        }
        if (!cur->isLeaf)
            traverse(cur->children[cur->count]);
    }

    void dealloc(BTreeNode<Record, order> *cur)
    {
        if (cur == nullptr)
            return;

        for (int i = 0; i < cur->count; i++)
            if (!cur->isLeaf)
                dealloc(cur->children[i]);

        delete cur;
    }

public:
    BTree()
    {
        this->root = nullptr;
    }

    ~BTree()
    {
        dealloc(this->root);
    }

    BTreeNode<Record, order> *search(Record target)
    {
        BTreeNode<Record, order> *tmp = root;
        while (tmp != nullptr)
        {
            int position = 0;
            while (position < tmp->count && tmp->values[position] < target)
                position++;
            if (position < tmp->count && tmp->values[position] == target)
                return tmp;
            else
                tmp = tmp->children[position];
        }
        return nullptr;
    }

    bool contains(Record val)
    {
        return search(val) != nullptr;
    }

    void insert(Record val)
    {
        if (this->root == nullptr)
            this->root = new BTreeNode<Record, order>(true);

        Record newVal;
        BTreeNode<Record, order> *newBranch = nullptr;
        insert(this->root, val, newBranch, newVal);
        if (newBranch != nullptr)
        {
            BTreeNode<Record, order> *tmp = this->root;
            this->root = new BTreeNode<Record, order>(false);
            this->root->children[0] = tmp;
            this->root->pushIn(newVal, newBranch);
        }
    }

    void remove(Record val)
    {
        remove(this->root, val);
        if (this->root->count <= 0)
        {
            BTreeNode<Record, order> *tmp = this->root;
            this->root = this->root->children[0];
            delete tmp;
        }
    }

    void traverse()
    {
        traverse(this->root);
        cout << endl;
    }
};

void test()
{
    BTree<int, 3> test;
    test.insert(1);
    test.insert(2);
    test.insert(3);
    test.insert(4);
    test.insert(5);
    test.insert(6);
    test.insert(6);
    test.insert(7);
    test.traverse();
    cout << (test.contains(7) ? "Contains 7" : "Not contains 7") << endl;
    cout << (test.contains(8) ? "Contains 8" : "Not contains 8") << endl;
    test.remove(2);
    test.traverse();
    test.remove(5);
    test.traverse();
    test.remove(4);
    test.traverse();
    test.remove(6);
    test.traverse();
    test.remove(6);
    test.traverse();
    test.remove(1);
    test.traverse();
    test.remove(3);
    test.traverse();
    cout << (test.contains(7) ? "Contains 7" : "Not contains 7") << endl;
    cout << (test.contains(1) ? "Contains 1" : "Not contains 1") << endl;
}

int main()
{
    test();
}