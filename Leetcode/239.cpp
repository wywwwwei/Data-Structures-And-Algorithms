/**
 * 239. 滑动窗口最大值
 * link：https://leetcode-cn.com/problems/sliding-window-maximum/
 */

/**
 * When sliding the window to the right:
 * assuming that from index [0...k] -> [1...k+1]
 * 1. If window[0] is the maximum:
 *    Compare window[k+1] to the maximum value of window[1...k]    =  Condition 2
 * 2. If window[0] is not the maximum:
 *    Compare window[k+1] to the maximum value of the current window
 * 
 * In the worst case, window[0] > window[1] >... > window[k+1] > window[k+1],
 * we need a structure to hold the maximum possible value of the current window (two-sided queue)
 * queue(i) > queue(j) when i < j
 *
 * Each time the window is moved, the index that does not belong to the current window is removed (front->back), 
 * and the elements that are smaller than the current element are removed (back->front), because they cannot be the maximum
 */

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (k <= 0)
            return {};

        deque<int> index;
        vector<int> result(nums.size() - k + 1, 0);
        int left;

        for (int i = 0; i < nums.size(); i++)
        {
            left = i + 1 - k;
            while (!index.empty() && nums[i] >= nums[index.back()])
                index.pop_back();
            if (!index.empty() && index.front() < left)
                index.pop_front();

            index.push_back(i);
            if (left >= 0)
                result[left] = nums[index.front()];
        }

        return result;
    }
};