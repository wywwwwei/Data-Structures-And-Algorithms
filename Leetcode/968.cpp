/**
 * 968. 监控二叉树  Recursion
 * link：https://leetcode-cn.com/problems/binary-tree-cameras/
 */

/**
 * There are essentially 3 states:
 * 1. There is a camera here.
 * 2. There is no camera but it is watched.
 * 3. It is not watched.
 * 
 * So for a node, from the bottom up
 * if it has a child node that is not watched, it must be a camera -> State 1
 * if all of its child nodes are watched, and there are cameras placed in them -> State 2
 * if all of its child nodes are watched, and there aren't any camera placed in them -> State 3
 */

class Solution
{
    enum State
    {
        k_null,
        k_camera,
        k_watched,
        k_unwatched
    };

    int result = 0;

public:
    int minCameraCover(TreeNode *root)
    {
        if (dfs(root) == State::k_unwatched)
            result++;
        return result;
    }

    State dfs(TreeNode *cur)
    {
        if (cur == nullptr)
            return State::k_null;

        State left = dfs(cur->left);
        State right = dfs(cur->right);

        if (left == State::k_unwatched || right == State::k_unwatched)
        {
            result++;
            return State::k_camera;
        }
        if (left == State::k_camera || right == State::k_camera)
        {
            return State::k_watched;
        }
        return State::k_unwatched;
    }
};