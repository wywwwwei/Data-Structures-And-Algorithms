#include <iostream>
#include <climits>

using namespace std;

// If you want to reduce the self-balancing time
// you can add a variable to store the height (Avoid repeated recursion)
struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int val, TreeNode *left = nullptr, TreeNode *right = nullptr)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

class AVLTree
{
    TreeNode *root;

//These functions are the same as binary search tree's.
    TreeNode *getMaxNode(TreeNode *cur)
    {
        if (cur == nullptr)
            return nullptr;
        while (cur->right != nullptr)
            cur = cur->right;
        return cur;
    }

    TreeNode *getMinNode(TreeNode *cur)
    {
        if (cur == nullptr)
            return nullptr;
        while (cur->left != nullptr)
            cur = cur->left;
        return cur;
    }

    void preOrderTraverse(TreeNode *cur)
    {
        if (cur == nullptr)
            return;
        cout << cur->val << " ";
        preOrderTraverse(cur->left);
        preOrderTraverse(cur->right);
    }

    void inOrderTraverse(TreeNode *cur)
    {
        if (cur == nullptr)
            return;
        inOrderTraverse(cur->left);
        cout << cur->val << " ";
        inOrderTraverse(cur->right);
    }

    void postOrderTraverse(TreeNode *cur)
    {
        if (cur == nullptr)
            return;
        postOrderTraverse(cur->left);
        postOrderTraverse(cur->right);
        cout << cur->val << " ";
    }

    void dealloc(TreeNode *cur)
    {
        if (cur == nullptr)
            return;

        dealloc(cur->left);
        dealloc(cur->right);
        delete cur;
    }

// The following functions are unique to AVLTree and include operations such as rotation and self-balancing
    int height(TreeNode *cur)
    {
        if (cur == nullptr)
            return 0;
        return max(height(cur->left), height(cur->right)) + 1;
    }

    int heightDiff(TreeNode *parent)
    {
        return height(parent->left) - height(parent->right);
    }

    TreeNode *LLRotate(TreeNode *parent)
    {
        TreeNode *tmp = parent->left;
        parent->left = tmp->right;
        tmp->right = parent;
        return tmp;
    }

    TreeNode *RRRotate(TreeNode *parent)
    {
        TreeNode *tmp = parent->right;
        parent->right = tmp->left;
        tmp->left = parent;
        return tmp;
    }

    TreeNode *LRRotate(TreeNode *parent)
    {
        parent->left = RRRotate(parent->left);
        return LLRotate(parent);
    }

    TreeNode *RLRotate(TreeNode *parent)
    {
        parent->right = LLRotate(parent->right);
        return RRRotate(parent);
    }

    TreeNode *balance(TreeNode *parent)
    {
        int diff = heightDiff(parent);
        if (diff > 1) //left-heavy
        {
            if (heightDiff(parent->left) > 0) // left left case
                return LLRotate(parent);
            else //left right case
                return LRRotate(parent);
        }
        else if (diff < -1) //right-heavy
        {
            if (heightDiff(parent->right) > 0) // right left case
                return RLRotate(parent);
            else //right right case
                return RRRotate(parent);
        }
        return parent;
    }

    TreeNode *insertAndBalance(TreeNode *cur, int val)
    {
        if (cur == nullptr)
            return new TreeNode(val);
        else if(cur->val == val)
            return cur;
        else if (cur->val > val)
            cur->left = insertAndBalance(cur->left, val);
        else
            cur->right = insertAndBalance(cur->right, val);

        cur = balance(cur);
        return cur;
    }

    TreeNode *removeAndBalance(TreeNode *cur, int val)
    {
        if (cur == nullptr)
            return nullptr;
        if (cur->val == val)
        {
            TreeNode *res = nullptr;
            if (cur->left == nullptr)
            {
                res = cur->right;
                delete cur;
            }
            else if (cur->left == nullptr)
            {
                res = cur->left;
                delete cur;
            }
            else
            {
                TreeNode *successor = getMinNode(cur->right);
                cur->val = successor->val;
                cur->right = removeAndBalance(cur->right, successor->val);
                res = balance(cur);
            }
            return res;
        }
        else if (cur->val > val)
            cur->left = removeAndBalance(cur->left, val);
        else
            cur->right = removeAndBalance(cur->right, val);
        return balance(cur);
    }

public:
    AVLTree()
    {
        this->root = nullptr;
    }

    ~AVLTree()
    {
        dealloc(this->root);
    }

    bool contains(int val)
    {
        return find(val) != nullptr;
    }

    TreeNode *find(int val)
    {
        TreeNode *tmp = root;
        while (tmp != nullptr)
        {
            if (val == tmp->val)
                return tmp;
            else if (val > tmp->val)
                tmp = tmp->right;
            else
                tmp = tmp->left;
        }
        return nullptr;
    }

    int getMin()
    {
        TreeNode *res = getMinNode(this->root);
        return (res == nullptr ? INT_MIN : res->val);
    }

    int getMax()
    {
        TreeNode *res = getMaxNode(this->root);
        return (res == nullptr ? INT_MIN : res->val);
    }

    void preOrderTraverse()
    {
        preOrderTraverse(this->root);
        cout << endl;
    }

    void inOrderTraverse()
    {
        inOrderTraverse(this->root);
        cout << endl;
    }

    void postOrderTraverse()
    {
        postOrderTraverse(this->root);
        cout << endl;
    }

    void insert(int val)
    {
        this->root = insertAndBalance(this->root, val);
    }

    void remove(int val)
    {
        this->root = removeAndBalance(this->root, val);
    }
};

void test()
{
    AVLTree test;
    test.insert(10);
    test.insert(12);
    test.insert(14);
    test.insert(16);
    test.insert(18);
    test.insert(18);
    test.insert(20);
    test.preOrderTraverse();
    test.inOrderTraverse();
    test.postOrderTraverse();
    cout << "Min: " << test.getMin() << "  Max: " << test.getMax() << endl;
    test.remove(16);
    test.preOrderTraverse();
    test.inOrderTraverse();
    test.postOrderTraverse();
    cout << "Min: " << test.getMin() << "  Max: " << test.getMax() << endl;
}

int main()
{
    test();
}