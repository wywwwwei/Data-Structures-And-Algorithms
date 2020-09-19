/**
 * 307. 区域和检索 - 数组可修改 线段树(树实现)
 * link：https://leetcode-cn.com/problems/range-sum-query-mutable/
 */

class NumArray
{
    struct TreeNode
    {
        int val;
        int left;
        TreeNode *left_ptr = nullptr;
        int right;
        TreeNode *right_ptr = nullptr;

        TreeNode(int val_, int left_, TreeNode *left_ptr_, int right_, TreeNode *right_ptr_)
            : val(val_), left(left_), left_ptr(left_ptr_), right(right_), right_ptr(right_ptr_) {}
            
        TreeNode(int left_, TreeNode *left_ptr_, int right_, TreeNode *right_ptr_)
            : left(left_), left_ptr(left_ptr_), right(right_), right_ptr(right_ptr_) {}
    };

    TreeNode *buildTree(vector<int> &nums, int left, int right)
    {
        if (left == right)
            return new TreeNode(nums[left], left, nullptr, right, nullptr);

        int mid = left + (right - left) / 2;
        TreeNode *cur = new TreeNode(left, buildTree(nums, left, mid), right, buildTree(nums, mid + 1, right));
        cur->val = cur->left_ptr->val + cur->right_ptr->val;

        return cur;
    }

    void update(TreeNode *cur, int i, int val)
    {
        if (cur->left == cur->right)
        {
            cur->val = val;
            return;
        }

        int mid = cur->left + (cur->right - cur->left) / 2;
        if (i <= mid)
            update(cur->left_ptr, i, val);
        else
            update(cur->right_ptr, i, val);
    }

    int calSum(TreeNode *cur, int left, int right)
    {
        if (cur->left == cur->right)
            return cur->val;

        int mid = cur->left + (cur->right - cur->left) / 2;
        if (left > mid)
            return calSum(cur->right_ptr, left, right);
        if (right <= mid)
            return calSum(cur->left_ptr, left, right);
        return calSum(cur->left_ptr, left, mid) + calSum(cur->right_ptr, mid + 1, right);
    }

    TreeNode *root;

public:
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 0)
            return;
        root = buildTree(nums, 0, n - 1);
    }

    void update(int i, int val)
    {
        update(root, i, val);
    }

    int sumRange(int i, int j)
    {
        return calSum(root, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */