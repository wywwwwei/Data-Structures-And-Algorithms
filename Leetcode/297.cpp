/**
 * 297. 二叉树的序列化与反序列化    Level Order Traversal
 * link：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/
 */

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string result;
        result += '[';

        queue<TreeNode *> level;
        level.push(root);
        while (!level.empty())
        {
            int n = level.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *tmp = level.front();
                level.pop();

                if (tmp == nullptr)
                {
                    result += "null,";
                    continue;
                }
                result += to_string(tmp->val);
                result += ',';
                level.push(tmp->left);
                level.push(tmp->right);
            }
        }
        if (result.length() > 1)
            result[result.length() - 1] = ']';

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        queue<TreeNode *> level;
        int index = 1;
        int val = 0;

        TreeNode *root;
        if (!getData(data, index, val))
            return nullptr;

        root = new TreeNode(val);
        level.push(root);
        while (!level.empty())
        {
            TreeNode *tmp = level.front();
            level.pop();
            if (getData(data, index, val))
            {
                tmp->left = new TreeNode(val);
                level.push(tmp->left);
            }
            if (getData(data, index, val))
            {
                tmp->right = new TreeNode(val);
                level.push(tmp->right);
            }
        }
        return root;
    }

    bool getData(string &text, int &index, int &val)
    {
        int begin = index;
        int number = 0;
        bool negative = false;
        while (index < text.length())
        {
            if (text[index] == ',' || text[index] == ']')
            {
                string temp = text.substr(begin, index - begin);
                index++;
                if (temp == "null")
                    return false;
                val = negative ? -number : number;
                return true;
            }
            else if (isdigit(text[index]))
            {
                number = number * 10 + (text[index] - '0');
            }
            else if (text[index] == '-')
            {
                negative = true;
            }
            index++;
        }
        return false;
    }
};