/**
 * 119. 杨辉三角 II
 * link：https://leetcode-cn.com/problems/pascals-triangle-ii/
 */

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result(rowIndex + 1, 1);

        // C(m,n) = n!/(m!(n-m)!)
        // C(m-1,n) = n!/((m-1)!(n-m+1)!) = C(m,n) * (n-m+1) / m 
        for (int i = 1; i <= rowIndex; ++i) 
            result[i] = 1LL * result[i - 1] * (rowIndex - i + 1) / i;

        return result;  
    }
};