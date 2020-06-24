#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode
{
    bool isEndOfWord = false;
    void setEndOfWord(bool _isEndOfWord)
    {
        this->isEndOfWord = _isEndOfWord;
    }

    virtual TrieNode *addChildren(char key) = 0;
    virtual TrieNode *getChildren(char key) = 0;
    virtual vector<pair<char, TrieNode *>> getAllChildren() = 0;
    virtual ~TrieNode() {}
};

struct HashTrieNode : public TrieNode
{
    unordered_map<char, HashTrieNode *> children;
    HashTrieNode() { children.clear(); }
    ~HashTrieNode() override
    {
        for (auto iter : children)
            delete iter.second;
    }

    TrieNode *addChildren(char key) override
    {
        TrieNode *res = getChildren(key);
        if (res != nullptr)
            return res;
        res = new HashTrieNode();
        children[key] = dynamic_cast<HashTrieNode *>(res);
        return res;
    }

    TrieNode *getChildren(char key) override
    {
        auto iter = children.find(key);
        if (iter != children.end())
        {
            return iter->second;
        }
        return nullptr;
    }

    vector<pair<char, TrieNode *>> getAllChildren() override
    {
        vector<pair<char, TrieNode *>> result;
        for (auto child : children)
        {
            result.emplace_back(make_pair(child.first, child.second));
        }
        return result;
    }
};

struct ArrayTrieNode : public TrieNode
{
    ArrayTrieNode *children[ALPHABET_SIZE];
    ArrayTrieNode()
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = nullptr;
    }
    ~ArrayTrieNode() override
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
            if (children[i])
                delete children[i];
    }

    TrieNode *addChildren(char key) override
    {
        TrieNode *res = getChildren(key);
        if (res != nullptr)
            return res;
        res = new ArrayTrieNode();
        children[key - 'a'] = dynamic_cast<ArrayTrieNode *>(res);
        return res;
    }

    TrieNode *getChildren(char key) override
    {
        return children[key - 'a'];
    }

    vector<pair<char, TrieNode *>> getAllChildren() override
    {
        vector<pair<char, TrieNode *>> result;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (children[i] != nullptr)
                result.emplace_back(make_pair('a' + i, children[i]));
        }
        return result;
    }
};

class Trie
{
    void printRecursive(TrieNode *cur, string &ob)
    {
        if (cur->isEndOfWord)
            cout << ob << endl;
        for (auto child : cur->getAllChildren())
        {
            ob.push_back(child.first);
            printRecursive(child.second, ob);
            ob.pop_back();
        }
    }

public:
    typedef enum TrieNodeType
    {
        HASH,
        ARRAY
    } TrieNodeType;
    TrieNode *root;

    Trie(TrieNodeType nodeType)
    {
        if (nodeType == TrieNodeType::HASH)
            root = new HashTrieNode();
        else
            root = new ArrayTrieNode();
    }
    ~Trie()
    {
        delete root;
    }

    void insert(const string &value)
    {
        TrieNode *tmp = root;
        for (auto v : value)
        {
            tmp = tmp->addChildren(v);
        }
        tmp->setEndOfWord(true);
    }

    bool contains(const string &value)
    {
        TrieNode *tmp = root;
        for (auto v : value)
        {
            tmp = tmp->getChildren(v);
            if (tmp == nullptr)
                return false;
        }

        return tmp->isEndOfWord;
    }

    void print()
    {
        string outputBuffer;
        printRecursive(root, outputBuffer);
    }
};

void test()
{
    Trie test(Trie::TrieNodeType::ARRAY);
    test.insert("hello");
    test.insert("hi");
    test.insert("helo");

    cout << (test.contains("hello") ? "Yes" : "No") << endl;
    cout << (test.contains("hi") ? "Yes" : "No") << endl;
    cout << (test.contains("helo") ? "Yes" : "No") << endl;
    cout << (test.contains("hel") ? "Yes" : "No") << endl;

    Trie test1(Trie::TrieNodeType::HASH);
    test1.insert("hello");
    test1.insert("hi");
    test1.insert("helo");

    cout << (test1.contains("hello") ? "Yes" : "No") << endl;
    cout << (test1.contains("hi") ? "Yes" : "No") << endl;
    cout << (test1.contains("helo") ? "Yes" : "No") << endl;
    cout << (test1.contains("hel") ? "Yes" : "No") << endl;

    test.print();
    test1.print();
}

int main()
{
    test();
}