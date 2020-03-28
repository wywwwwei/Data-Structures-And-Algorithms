/**
 * 820. 单词的压缩编码 Trie
 * link：https://leetcode-cn.com/problems/short-encoding-of-words/
 */

using TrieNode = struct TrieNode
{
    bool isEndOfWord;
    int compress_depth;
    unordered_map<char, TrieNode *> children;

    TrieNode(int _compress_depth)
    {
        this->compress_depth = _compress_depth;
        this->isEndOfWord = false;
    }
};

class TrieTree
{
private:
    TrieNode *root = nullptr;
    int compress = 0;

public:
    TrieTree(vector<string> &words)
    {
        root = new TrieNode(1);

        for (const string &word : words)
        {
            TrieNode *temp = root;
            for (int i = word.length() - 1; i >= 0; i--)
            {
                if (temp->children.find(word[i]) == temp->children.end())
                {
                    if (temp->isEndOfWord)
                    {
                        temp->isEndOfWord = false;
                        compress -= temp->compress_depth;
                    }
                    TrieNode *create = new TrieNode(temp->compress_depth + 1);
                    temp->children[word[i]] = create;
                    if (i == 0)
                    {
                        compress += temp->compress_depth + 1;
                        create->isEndOfWord = true;
                    }
                }
                temp = temp->children[word[i]];
            }
        }
    }

    int getCompressCount() const
    {
        return compress;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieTree result(words);
        return result.getCompressCount();
    }
};