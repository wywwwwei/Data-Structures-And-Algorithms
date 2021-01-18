/**
 * 721. 账户合并    Hash + Union-find
 * link：https://leetcode-cn.com/problems/accounts-merge/
 */

class Solution
{
    int findParent(vector<int> &parent, int a)
    {
        if (parent[a] != a)
            parent[a] = findParent(parent, parent[a]);
        return parent[a];
    }

    void merge(vector<int> &parent, int a, int b)
    {
        int parent_a = findParent(parent, a);
        int parent_b = findParent(parent, b);
        parent[parent_a] = parent_b;
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, int> email2idx;
        unordered_map<string, string> email2name;

        int countEmail = 0;
        for (auto &account : accounts)
        {
            string &name = account[0];
            int n = account.size();
            for (int i = 1; i < n; i++)
            {
                string &email = account[i];
                if (email2idx.find(email) == email2idx.end())
                {
                    email2idx[email] = countEmail++;
                    email2name[email] = name;
                }
            }
        }

        vector<int> parent(countEmail);
        iota(parent.begin(), parent.end(), 0);

        for (const auto &account : accounts)
        {
            int firstIdx = email2idx[account[1]];
            int n = account.size();
            for (int i = 2; i < n; i++)
            {
                int curIdx = email2idx[account[i]];
                merge(parent, curIdx, firstIdx);
            }
        }

        unordered_map<int, vector<string>> idx2Emails;
        for (const auto &kv : email2idx)
            idx2Emails[findParent(parent, kv.second)].emplace_back(kv.first);

        vector<vector<string>> result;
        for (auto &kv : idx2Emails)
        {
            sort(kv.second.begin(), kv.second.end());
            vector<string> account(move(kv.second));
            account.insert(account.begin(), email2name[account[0]]);
            result.emplace_back(move(account));
        }

        return result;
    }
};