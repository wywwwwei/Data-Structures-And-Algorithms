/**
 * 466. 统计重复个数
 * link：https://leetcode-cn.com/problems/count-the-repetitions/
 */

/**
 * Find a pattern of repetition and s1 is composed of three parts:
 * Not repeat in the front, repeat pattern in the middle and the remain in the tail(left part of repeat pattern)
 * 
 * It is like a finite circulating decimal. e.g. 0.3454545454
 * it is composed of 3 and repeated 45 and 4 
 */
class Solution
{
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        if (n1 <= 0)
            return 0;

        vector<int> index_record(s2.length() + 1, 0);
        vector<int> s2_count_record(s2.length() + 1, 0);
        int cur_index = 0;
        int cur_s2_count = 0;
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < s1.length(); j++)
            {
                if (s1[j] == s2[cur_index])
                    cur_index++;
                if (cur_index == s2.length())
                {
                    cur_index = 0;
                    cur_s2_count++;
                }
            }

            index_record[i] = cur_index;
            s2_count_record[i] = cur_s2_count;

            for (int j = 0; j < i; j++)
            {
                if (cur_index == index_record[j])
                {
                    int before_loop_count = s2_count_record[j];
                    int loop_count = (cur_s2_count - before_loop_count) * ((n1 - j - 1) / (i - j));
                    int remain_count = s2_count_record[j + (n1 - j - 1) % (i - j)] - s2_count_record[j];
                    return (before_loop_count + loop_count + remain_count) / n2;
                }
            }
        }

        return s2_count_record[n1 - 1] / n2;
    }
};