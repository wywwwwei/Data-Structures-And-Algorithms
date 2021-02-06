/**
 * 1423. 可获得的最大点数
 * link：https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/
 */

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int result = sum;
        for (int i = 0; i < k; i++)
        {
            sum -= cardPoints[k - 1 - i];
            sum += cardPoints[n - 1 - i];
            result = max(result, sum);
        }
        return result;
    }
};