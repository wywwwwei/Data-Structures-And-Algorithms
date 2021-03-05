/**
 * 503. 下一个更大元素 II
 * link：https://leetcode-cn.com/problems/next-greater-element-ii/
 */

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> result(n, -1);
        stack<int> st;

        for (int i = 0; i < n * 2 - 1; ++i)
        {
            while (!st.empty() && nums[i % n] > nums[st.top()])
            {
                result[st.top()] = nums[i % n];
                st.pop();
            }
            st.push(i % n);
        }
        return result;
    }
};