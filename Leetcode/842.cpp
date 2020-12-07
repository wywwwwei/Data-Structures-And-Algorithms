/**
 * 842. 将数组拆分成斐波那契序列
 * link：https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence/
 */

/**
 * Pruning:
 * When path.size() >= 2:
 * 1. The current number of digits must be larger than or equal to the previous two
 * 2. Exit when current number > the sum of the previous two numbers
 * 3. Exit when current number > INT_MAX
 * 4. Exit after checking 0
 */
class Solution
{
    vector<int> path;

    bool search(string &s, int index, int lastLen)
    {
        if (index >= s.length())
            return path.size() >= 3;
        if (s.length() - index < lastLen)
            return false;

        long long cur = 0;
        int tmp_index = index;

        // Pruning 1:
        if (path.size() >= 2)
            while (--lastLen > 0)
                cur = cur * 10 + (s[index++] - '0');

        while (index < s.length())
        {
            cur = cur * 10 + (s[index++] - '0');
            // Pruning 3:
            if (cur > INT_MAX)
                break;

            if (path.size() < 2 || 0LL + path[path.size() - 1] + path[path.size() - 2] == cur)
            {
                path.push_back(cur);
                if (search(s, index, index - tmp_index))
                    return true;
                path.pop_back();
                if (path.size() >= 2)
                    return false;
            }
            else if (0LL + path[path.size() - 1] + path[path.size() - 2] < cur) // Pruning 2:
                return false;
            
            // Pruning 4:
            if (cur == 0)
                break;
        }
        return false;
    }

public:
    vector<int> splitIntoFibonacci(string S)
    {
        search(S, 0, 0);
        return path;
    }
};