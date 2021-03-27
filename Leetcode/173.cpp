/**
 * 173. 二叉搜索树迭代器
 * link：https://leetcode-cn.com/problems/binary-search-tree-iterator/
 */

class BSTIterator
{
private:
    TreeNode *cur;
    vector<TreeNode *> stk;

public:
    BSTIterator(TreeNode *root) : cur(root) {}

    int next()
    {
        while (cur != nullptr)
        {
            stk.emplace_back(cur);
            cur = cur->left;
        }

        cur = stk.back();
        stk.pop_back();

        int result = cur->val;
        cur = cur->right;
        return result;
    }

    bool hasNext()
    {
        return cur != nullptr || !stk.empty();
    }
};

// class BSTIterator
// {
//     using nodeBool = pair<TreeNode *, bool>;
//     vector<nodeBool> stk;

// public:
//     BSTIterator(TreeNode *root)
//     {
//         stk.emplace_back(root, false);
//     }

//     int next()
//     {
//         if (!stk.back().second)
//             hasNext();

//         auto cur = stk.back();
//         stk.pop_back();
//         if (cur.first->right)
//             stk.emplace_back(cur.first->right, false);

//         return cur.first->val;
//     }

//     bool hasNext()
//     {
//         if (stk.empty())
//             return false;

//         auto &cur = stk.back();
//         auto curPtr = cur.first;
//         if (!cur.second)
//         {
//             cur.second = true;
//             while (curPtr->left != nullptr)
//             {
//                 stk.emplace_back(curPtr->left, true);
//                 curPtr = curPtr->left;
//             }
//         }

//         return true;
//     }
// };