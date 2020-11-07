/**
 * 327. 区间和的个数 Segment Tree
 * link：https://leetcode-cn.com/problems/count-of-range-sum/
 */

class Solution
{
    struct Node
    {
        long left;
        long right;
        int val = 0;
        Node *left_child = nullptr;
        Node *right_child = nullptr;
        Node(long _left, long _right) : left(_left), right(_right) {}
    };

    class SegmentTree
    {
        Node *root;
        void add(Node *cur, long val)
        {
            cur->val++;
            if (cur->left == cur->right)
                return;
            long mid = cur->left + (cur->right - cur->left) / 2;
            if (val <= mid)
            {
                if (cur->left_child == nullptr)
                    cur->left_child = new Node(cur->left, mid);
                add(cur->left_child, val);
            }
            else
            {
                if (cur->right_child == nullptr)
                    cur->right_child = new Node(mid + 1, cur->right);
                add(cur->right_child, val);
            }
        }

        int get(Node *cur, long &left, long &right)
        {
            if (cur == nullptr || left > cur->right || right < cur->left)
                return 0;
            if (left <= cur->left && right >= cur->right)
                return cur->val;
            return get(cur->left_child, left, right) + get(cur->right_child, left, right);
        }

    public:
        SegmentTree(long left, long right)
        {
            root = new Node(left, right);
        }

        void add(long val)
        {
            add(root, val);
        }

        int get(long left, long right)
        {
            return get(root, left, right);
        }
    };

public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        long sum = 0;
        vector<long> preSum(n + 1, 0);
        long left = LONG_MAX, right = LONG_MIN;
        for (int i = 0; i < n; i++)
        {
            left = min({left, sum, sum - lower, sum - upper});
            right = max({right, sum, sum - lower, sum - upper});
            preSum[i] = sum;
            sum += nums[i];
        }
        left = min({left, sum, sum - lower, sum - upper});
        right = max({right, sum, sum - lower, sum - upper});
        preSum[n] = sum;

        int result = 0;
        SegmentTree st(left, right);
        for (const auto &sum : preSum)
        {
            result += st.get(sum - upper, sum - lower);
            st.add(sum);
        }
        return result;
    }
};