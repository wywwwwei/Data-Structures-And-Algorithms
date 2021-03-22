/**
 * 341. 扁平化嵌套列表迭代器    dfs recursion
 * link：https://leetcode-cn.com/problems/flatten-nested-list-iterator/
 */

class NestedIterator
{
    vector<int> result;
    int idx = 0;

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        dfs(nestedList);
    }

    void dfs(const vector<NestedInteger> &nestedList)
    {
        for (const auto &val : nestedList)
        {
            if (val.isInteger())
                result.emplace_back(val.getInteger());
            else
                dfs(val.getList());
        }
    }

    int next()
    {
        return result[idx++];
    }

    bool hasNext()
    {
        return idx < result.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */