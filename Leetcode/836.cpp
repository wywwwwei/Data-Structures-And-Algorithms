/**
 * 836. 矩形重叠 投影重叠
 * link：https://leetcode-cn.com/problems/rectangle-overlap/
 */

class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        return !(
            // The projections in the x-axis do not coincide
            rec1[0] >= rec2[2] || rec1[2] <= rec2[0] || rec1[1] >= rec2[3] ||
            rec1[3] <= rec2[1]
            // The projections in the y-axis do not coincide
        );
    }
};