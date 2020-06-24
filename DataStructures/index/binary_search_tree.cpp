#include <limits>
#include <iostream>

using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int v, TreeNode *left = nullptr, TreeNode *right = nullptr)
    {
        this->val = v;
        this->left = left;
        this->right = right;
    }
};

class BinarySearchTree
{
    TreeNode *root;

    TreeNode *deleteByCopy(TreeNode *cur, int val)
    {
        if (cur == nullptr)
            return nullptr;
        if (cur->val > val)
            cur->left = deleteByCopy(cur->left, val);
        else if (cur->val < val)
            cur->right = deleteByCopy(cur->right, val);
        else
        {
            if (cur->left == nullptr)
            {
                TreeNode *tmp = cur->right;
                delete (cur);
                return tmp;
            }
            else if (cur->right == nullptr)
            {
                TreeNode *tmp = cur->left;
                delete (cur);
                return tmp;
            }
            else
            {
                TreeNode *successor = getMinNode(cur->right);
                cur->val = successor->val;
                cur->right = deleteByCopy(cur->right, successor->val);
            }
        }
        return cur;
    }

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

    void preorderTraverse(TreeNode *cur)
    {
        if (cur == nullptr)
            return;

        cout << cur->val << " ";
        preorderTraverse(cur->left);
        preorderTraverse(cur->right);
    }

    void inorderTraverse(TreeNode *cur)
    {
        if (cur == nullptr)
            return;

        inorderTraverse(cur->left);
        cout << cur->val << " ";
        inorderTraverse(cur->right);
    }

    void postorderTraverse(TreeNode *cur)
    {
        if (cur == nullptr)
            return;

        postorderTraverse(cur->left);
        postorderTraverse(cur->right);
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

public:
    BinarySearchTree()
    {
        this->root = nullptr;
    }

    ~BinarySearchTree()
    {
        dealloc(this->root);
    }

    void insert(int val)
    {
        if (this->root == nullptr)
        {
            this->root = new TreeNode(val);
            return;
        }
        TreeNode *tmp = this->root;
        TreeNode *lastTmp;
        while (tmp != nullptr)
        {
            lastTmp = tmp;
            if (tmp->val == val)
                return;
            else if (tmp->val > val)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
        if (lastTmp->val < val)
            lastTmp->right = new TreeNode(val);
        else
            lastTmp->left = new TreeNode(val);
    }

    TreeNode *find(int val)
    {
        TreeNode *tmp = this->root;
        while (tmp != nullptr)
        {
            if (tmp->val == val)
                return tmp;
            else if (tmp->val > val)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
        return nullptr;
    }

    bool contains(int val)
    {
        return find(val) != nullptr;
    }

    void deleteByCopy(int val)
    {
        this->root = deleteByCopy(this->root, val);
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

    void preorderTraverse()
    {
        preorderTraverse(this->root);
        cout << endl;
    }

    void inorderTraverse()
    {
        inorderTraverse(this->root);
        cout << endl;
    }

    void postorderTraverse()
    {
        postorderTraverse(this->root);
        cout << endl;
    }
};

void test()
{
    BinarySearchTree test;
    test.insert(10);
    test.insert(5);
    test.insert(15);
    test.insert(2);
    test.insert(8);
    test.insert(12);
    test.insert(18);
    test.insert(13);
    cout << (test.contains(18) ? 1 : 0) << "  " << (test.contains(0) ? 1 : 0) << endl;
    cout << test.getMax() << "  " << test.getMin() << endl;
    test.preorderTraverse();
    test.inorderTraverse();
    test.postorderTraverse();
    test.deleteByCopy(10);
    cout << (test.contains(10) ? 1 : 0) << "  " << (test.contains(15) ? 1 : 0) << endl;
    test.inorderTraverse();
}

int main()
{
    test();
}