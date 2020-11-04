/**
 * 127. 单词接龙    双向广度优先搜索
 * link：https://leetcode-cn.com/problems/word-ladder/
 */

class Solution
{
    unordered_map<string, int> str2id;
    vector<vector<int>> graph;
    int nodes = 0;

    void addNode(string &word)
    {
        if (str2id.find(word) == str2id.end())
        {
            str2id[word] = nodes++;
            graph.emplace_back();
        }
    }

    void addEdges(string &word)
    {
        addNode(word);
        int word_id = str2id[word];
        for (char &it : word)
        {
            char tmp = it;
            it = '*';
            addNode(word);
            int connect = str2id[word];
            graph[word_id].push_back(connect);
            graph[connect].push_back(word_id);
            it = tmp;
        }
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        for (auto &word : wordList)
            addEdges(word);
        addEdges(beginWord);
        if (str2id.find(endWord) == str2id.end())
            return 0;

        int beginID = str2id[beginWord];
        int endID = str2id[endWord];
        queue<int> beginQueue;
        vector<int> beginPath(nodes, INT_MAX);
        queue<int> endQueue;
        vector<int> endPath(nodes, INT_MAX);

        beginQueue.push(beginID);
        endQueue.push(endID);
        beginPath[beginID] = 0;
        endPath[endID] = 0;

        while (!beginQueue.empty() && !endQueue.empty())
        {
            int tmp = beginQueue.size();
            for (int i = 0; i < tmp; i++)
            {
                int cur = beginQueue.front();
                beginQueue.pop();
                if (endPath[cur] != INT_MAX)
                    return (beginPath[cur] + endPath[cur]) / 2 + 1;
                for (const int &node : graph[cur])
                {
                    if (beginPath[node] == INT_MAX)
                    {
                        beginPath[node] = beginPath[cur] + 1;
                        beginQueue.push(node);
                    }
                }
            }

            tmp = endQueue.size();
            for (int i = 0; i < tmp; i++)
            {
                int cur = endQueue.front();
                endQueue.pop();
                if (beginPath[cur] != INT_MAX)
                    return (beginPath[cur] + endPath[cur]) / 2 + 1;
                for (const int &node : graph[cur])
                {
                    if (endPath[node] == INT_MAX)
                    {
                        endPath[node] = endPath[cur] + 1;
                        endQueue.push(node);
                    }
                }
            }
        }
        return 0;
    }
};