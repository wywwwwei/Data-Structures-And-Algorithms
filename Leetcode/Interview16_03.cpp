/**
 * 面试题 16.03. 交点
 * link：https://leetcode-cn.com/problems/intersection-lcci/
 */

/**
 * Method 1: Parametric equation -> parallel / intersect -> whether the intersection point is on the line segment
 * Method 2: Cross Product -> parallel or collinear -> conincide -> if intersect -> find the intersection point according to the area ratio
 */

class Solution
{
public:
    vector<double> intersection(vector<int> &start1, vector<int> &end1, vector<int> &start2, vector<int> &end2)
    {
        int x1 = start1[0], y1 = start1[1];
        int x2 = end1[0], y2 = end1[1];
        int x3 = start2[0], y3 = start2[1];
        int x4 = end2[0], y4 = end2[1];

        int diff_x_2_1 = x2 - x1;
        int diff_y_2_1 = y2 - y1;
        int diff_x_3_1 = x3 - x1;
        int diff_y_3_1 = y3 - y1;
        int diff_x_4_3 = x4 - x3;
        int diff_y_4_3 = y4 - y3;
        
        //Parallel
        if (diff_x_2_1 * diff_y_4_3 == diff_x_4_3 * diff_y_2_1)
        {
            //collinear
            if (diff_x_3_1 * diff_y_2_1 == diff_x_2_1 * diff_y_3_1)
            {
                bool inverse = false;
                //coincide
                if (x1 == x2)
                {
                    swap(x1, y1);
                    swap(x2, y2);
                    swap(x3, y3);
                    swap(x4, y4);
                    inverse = true;
                }

                if (x1 > x2)
                {
                    swap(x1, x2);
                    swap(y1, y2);
                }
                if (x3 > x4)
                {
                    swap(x3, x4);
                    swap(y3, y4);
                }
                if (x1 > x3)
                {
                    swap(x1, x3);
                    swap(x2, x4);
                    swap(y1, y3);
                    swap(y2, y4);
                }
                bool coincide1 = x1 <= x3 && x2 >= x3;
                bool coincide2 = x1 <= x4 && x2 >= x4;
                double result_x, result_y;
                if (coincide1)
                    result_x = x3, result_y = y3;
                else if (coincide2)
                    result_x = x4, result_y = y4;
                else
                    return {};

                if (inverse)
                    swap(result_x, result_y);
                return {result_x, result_y};
            }
            else
            {
                return {};
            }
        }
        else
        {
            double t1 = (double)(x3 * diff_y_4_3 + y1 * diff_x_4_3 - y3 * diff_x_4_3 - x1 * diff_y_4_3) / (diff_x_2_1 * diff_y_4_3 - diff_x_4_3 * diff_y_2_1);
            double t2 = (double)(x1 * diff_y_2_1 + y3 * diff_x_2_1 - y1 * diff_x_2_1 - x3 * diff_y_2_1) / (diff_x_4_3 * diff_y_2_1 - diff_x_2_1 * diff_y_4_3);
            if (t1 >= 0.0 && t1 <= 1.0 && t2 >= 0.0 && t2 <= 1.0)
            {
                return {x1 + t1 * diff_x_2_1, y1 + t1 * diff_y_2_1};
            }
        }
        return {};
    }
};