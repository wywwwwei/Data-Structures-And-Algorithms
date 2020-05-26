/**
 * 974. 和可被 K 整除的子数组 prefix sum + hash
 * link：https://leetcode-cn.com/problems/subarray-sums-divisible-by-k/
 */

class Solution
{
public:
    int subarraysDivByK(vector<int> &A, int K)
    {
        unordered_map<int, int> record{{0, 1}};
        int result = 0;

        int cur = 0;
        int sum = 0;
        for (auto &num : A)
        {
            sum += num;
            cur = (sum % K + K) % K;
            if (record.find(cur) != record.end())
                result += record[cur];
            record[cur]++;
        }

        return result;
    }
};