#include <iostream>
#include <cstring>

using namespace std;

#define MIN_KEY(x) ((x + 1) / 2 - 1)

//External Searching
//The implementation of b+ tree is basically the same as b tree,
//the difference is that for leaf nodes and internal nodes, b+ tree needs to be processed separately.
template <class Record, int order>
struct BPTreeNode
{
    Record values[order - 1];
    BPTreeNode<Record, order> *children[order];
    int count;
    bool isLeaf;

    BPTreeNode(bool isLeaf)
    {
        this->count = 0;
        for (int i = 0; i < order; i++)
            children[i] = nullptr;
        this->isLeaf = isLeaf;
    }

    bool isFull()
    {
        return this->count >= order - 1;
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
    void pushIn(Record &val, BPTreeNode<Record, order> *branch)
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
    void pushIn(Record &val, BPTreeNode<Record, order> *branch, int insertPos)
    {
        memmove(&this->values[insertPos + 1], &this->values[insertPos], sizeof(Record) * (this->count - insertPos));
        this->values[insertPos] = val;
        if (branch)
            this->children[insertPos + 1] = branch;
        this->count++;
    }

    //For the leaf node, splitting generates an index entry of the new leaf node,
    //and the internal node is the same as the b-tree
    void splitNode(Record &val, BPTreeNode<Record, order> *&newBranch, int &newVal)
    {
        int insertPos;
        if (indexInNode(val, insertPos))
            return;

        BPTreeNode<Record, order> *extraBranch = newBranch;
        newBranch = new BPTreeNode<Record, order>(this->isLeaf);
        int mid;
        if (isLeaf)
            mid = (order - 1) / 2;
        else
            mid = order / 2;
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

        newBranch->children[0] = this->children[this->count];
        if (isLeaf)
        {
            newVal = newBranch->values[0];
            newBranch->children[0] = this->children[0];
            this->children[0] = newBranch;
        }
        else
        {
            newVal = this->values[this->count - 1];
            newBranch->children[0] = this->children[this->count];
            this->count--;
        }
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
        BPTreeNode<Record, order> *searchNode = this->children[position + 1];
        while (!searchNode->isLeaf)
            searchNode = searchNode->children[0];
        return searchNode->values[0];
    }

    //For the leaf node, after borrowing, the corresponding index node needs to be copied from right child,
    //and the internal node is the same as the b-tree
    void borrowFromLeft(int position)
    {
        BPTreeNode<Record, order> *child = this->children[position];
        BPTreeNode<Record, order> *sibling = this->children[position - 1];

        memmove(&child->values[1], child->values, sizeof(Record) * child->count);

        if (child->isLeaf)
        {
            child->values[0] = sibling->values[sibling->count - 1];
            this->values[position - 1] = child->values[0];
        }
        else
        {
            memmove(&child->children[1], child->children, sizeof(Record) * (child->count + 1));
            child->values[0] = this->values[position - 1];
            child->children[0] = sibling->children[sibling->count];
            this->values[position - 1] = sibling->values[sibling->count - 1];
        }

        sibling->count--;
        child->count++;
    }

    void borrowFromRight(int position)
    {
        BPTreeNode<Record, order> *child = this->children[position];
        BPTreeNode<Record, order> *sibling = this->children[position + 1];

        if (child->isLeaf)
            child->values[child->count] = sibling->values[0];
        else
        {
            child->values[child->count] = this->values[position];
            child->children[child->count + 1] = sibling->children[0];
            this->values[position] = sibling->values[0];
            memmove(sibling->children, &sibling->children[1], sizeof(Record) * sibling->count);
        }

        memmove(sibling->values, &sibling->values[1], sizeof(Record) * (sibling->count - 1));
        if (child->isLeaf)
            this->values[position] = sibling->values[0];

        sibling->count--;
        child->count++;
    }

    //For the leaf node, merging does not need to merge index nodes,
    //and the internal node is the same as the b-tree
    void merge(int position)
    {
        BPTreeNode<Record, order> *child = this->children[position];
        BPTreeNode<Record, order> *sibling = this->children[position + 1];

        if (!child->isLeaf)
        {
            child->values[child->count++] = this->values[position];
            memmove(&child->children[child->count], sibling->children, sizeof(Record) * (sibling->count + 1));
        }
        memmove(&child->values[child->count], sibling->values, sizeof(Record) * sibling->count);

        child->count += sibling->count;
        if (child->isLeaf)
            child->children[0] = sibling->children[0];

        delete sibling;

        memmove(&this->values[position], &this->values[position + 1], sizeof(Record) * (this->count - position - 1));
        memmove(&this->children[position + 1], &this->children[position + 2], sizeof(Record) * (this->count - position - 1));
        this->count--;
    }
};

template <class Record, int order>
class BPTree
{
    BPTreeNode<Record, order> *root;

    void insert(BPTreeNode<Record, order> *cur, Record &val, BPTreeNode<Record, order> *&newBranch, Record &newVal)
    {
        int insertPos = 0;
        if (cur->indexInNode(val, insertPos))
            return;

        if (cur->isLeaf)
        {
            if (cur->isFull())
                cur->splitNode(val, newBranch, newVal);
            else
                cur->pushIn(val, nullptr, insertPos);
            return;
        }

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

    void remove(BPTreeNode<Record, order> *cur, Record &val)
    {
        int position = 0;
        bool existed = cur->indexInNode(val, position);
        if (cur->isLeaf)
        {
            if (existed)
                cur->removeFromLeaf(val, position);
            return;
        }

        if (existed)
            position++;
        remove(cur->children[position], val);
        BPTreeNode<Record, order> *needReplace = cur;
        if (cur->children[position]->count < MIN_KEY(order))
        {
            if (position > 0 && cur->children[position - 1]->count > MIN_KEY(order))
                cur->borrowFromLeft(position);
            else if (position < cur->count && cur->children[position + 1]->count > MIN_KEY(order))
                cur->borrowFromRight(position);
            else
            {
                if (position != cur->count)
                {
                    cur->merge(position);
                    needReplace = cur->children[position];
                }
                else
                {
                    cur->merge(position - 1);
                    needReplace = cur->children[position - 1];
                }
            }
        }

        //the corresponding index node needs to be copied from right child
        if (existed && needReplace->indexInNode(val, position))
            needReplace->values[position] = needReplace->getSuccessor(position);
    }

    void traverse(BPTreeNode<Record, order> *cur)
    {
        if (cur == nullptr)
            return;
        while (!cur->isLeaf)
            cur = cur->children[0];
        while (cur != nullptr)
        {
            for (int i = 0; i < cur->count; i++)
                cout << cur->values[i] << " ";
            cur = cur->children[0];
            if (cur)
                cout << "-> ";
        }
    }

    void dealloc(BPTreeNode<Record, order> *cur)
    {
        if (cur == nullptr)
            return;
        if (!cur->isLeaf)
            for (int i = 0; i <= cur->count; i++)
                dealloc(cur->children[i]);
        delete cur;
    }

public:
    BPTree()
    {
        this->root = nullptr;
    }
    ~BPTree()
    {
        dealloc(this->root);
    }

    BPTreeNode<Record, order> *search(Record val)
    {
        if (this->root == nullptr)
            return nullptr;
        BPTreeNode<Record, order> *tmp = this->root;
        int position = 0;
        while (!tmp->isLeaf)
        {
            if (tmp->indexInNode(val, position))
                tmp = tmp->children[position + 1];
            else
                tmp = tmp->children[position];
        }
        if (tmp->indexInNode(val, position))
            return tmp;
        return nullptr;
    }

    bool contains(Record val)
    {
        return (search(val) != nullptr);
    }

    void insert(Record val)
    {
        if (this->root == nullptr)
            this->root = new BPTreeNode<Record, order>(true);
        BPTreeNode<Record, order> *newBranch = nullptr;
        Record newVal;
        insert(this->root, val, newBranch, newVal);
        if (newBranch != nullptr)
        {
            BPTreeNode<Record, order> *tmp = this->root;
            this->root = new BPTreeNode<Record, order>(false);
            this->root->pushIn(newVal, newBranch);
            this->root->children[0] = tmp;
        }
    }

    void remove(Record val)
    {
        remove(this->root, val);
        if (this->root->count <= 0)
        {
            BPTreeNode<Record, order> *tmp = this->root;
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
    BPTree<int, 4> test;
    test.insert(1);
    test.insert(2);
    test.insert(3);
    test.insert(4);
    test.insert(5);
    test.insert(8);
    test.insert(7);
    test.insert(6);
    test.insert(10);
    test.insert(9);
    test.traverse();
    test.remove(8);
    test.remove(10);
    test.remove(1);
    test.traverse();
    test.remove(9);
    test.remove(7);
    test.remove(2);
    test.traverse();
    test.remove(5);
    test.traverse();
    cout << (test.contains(6) ? "Contain 6" : "Not contain 6") << endl;
    cout << (test.contains(7) ? "Contain 7" : "Not contain 7") << endl;
}

int main()
{
    test();
}