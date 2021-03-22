/**
 * 341. 扁平化嵌套列表迭代器    dfs iteration
 * link：https://leetcode-cn.com/problems/flatten-nested-list-iterator/
 */

class NestedIterator
{
    using Iter = vector<NestedInteger>::iterator;
    vector<pair<Iter, Iter>> stk;

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        stk.emplace_back(nestedList.begin(), nestedList.end());
    }

    int next()
    {
        return (stk.back().first++)->getInteger();
    }

    bool hasNext()
    {
        while (!stk.empty())
        {
            auto &t = stk.back();
            if (t.first == t.second)
            {
                stk.pop_back();
                continue;
            }

            if (t.first->isInteger())
                return true;

            auto &&tList = (t.first++)->getList();
            stk.emplace_back(tList.begin(), tList.end());
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */