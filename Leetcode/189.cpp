/**
 * 189. 旋转数组    Cyclic Replacements
 * link：https://leetcode-cn.com/problems/rotate-array/
 */

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;

        int count = gcd(k, n);
        for (int i = 0; i < count; i++)
        {
            int cur = i;
            int prev = nums[cur];
            do
            {
                int next = (cur + k) % n;
                swap(prev, nums[next]);
                cur = next;
            } while (cur != i);
        }
    }
};
