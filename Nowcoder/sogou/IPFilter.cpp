/**
 * [编程题]IP过滤器
 * https://www.nowcoder.com/questionTerminal/8389e1ccd47d40ba859c2497a428d0ca
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX_RULE 100
#define MAX_INPUT 50
#define CHILD_NUM 12

struct TrieNode
{
    bool isEnd;
    TrieNode *child[CHILD_NUM];

    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < CHILD_NUM; i++)
            child[i] = nullptr;
    }
};

class Trie
{
    TrieNode *root = nullptr;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void add(const string &rule)
    {
        TrieNode *cur = root;
        for (const char &c : rule)
        {
            int pos = isdigit(c) ? (c - '0') : ((c == '*') ? 10 : 11);
            if (cur->child[pos] == nullptr)
                cur->child[pos] = new TrieNode();
            cur = cur->child[pos];
        }
        cur->isEnd = true;
    }

    bool search(const string &ip)
    {
        return search(root, ip, 0);
    }

    // dfs search
    // * match a sequence of numbers
    bool search(TrieNode *cur, const string &ip, int index)
    {
        if (cur == nullptr)
            return false;
        if (index >= ip.length())
            return cur->isEnd;

        bool result = false;
        if (isdigit(ip[index]))
        {
            if (cur->child[ip[index] - '0'] != nullptr)
                result |= search(cur->child[ip[index] - '0'], ip, index + 1);
            if (cur->child[10] != nullptr)
            {
                while (index < ip.length() && isdigit(ip[++index]));
                result |= search(cur->child[10], ip, index);
            }
        }
        else
        {
            if (cur->child[11] != nullptr)
                result |= search(cur->child[11], ip, index + 1);
        }
        return result;
    }
};

// overload operator *
string operator*(string s, size_t count)
{
    string ret;
    for (size_t i = 0; i < count; ++i)
    {
        ret = ret + s;
    }
    return ret;
}

Trie t;
int main()
{
    int rule_num = 0;
    int input_num = 0;

    cin >> rule_num >> input_num;
    string cur;
    int dot_count;
    for (int i = 0; i < rule_num; i++)
    {
        cin >> cur;

        // Make all rules conform to the format of *.*.*.*
        dot_count = count(cur.begin(), cur.end(), '.');
        if (dot_count < 3)
        {
            if (cur[0] == '*')
                cur = string("*.") * (3 - dot_count) + cur;
            else if (cur[cur.length() - 1] == '*')
                cur = cur + string(".*") * (3 - dot_count);
        }
        t.add(cur);
    }

    for (int i = 0; i < input_num; i++)
    {
        cin >> cur;
        cout << (t.search(cur) ? 1 : 0) << " ";
    }
}