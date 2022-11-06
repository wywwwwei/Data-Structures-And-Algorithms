/**
 * 1678. 设计 Goal 解析器
 * link：https://leetcode.cn/problems/goal-parser-interpretation/
 */

class Solution
{
public:
    string interpret(string command)
    {
        string result;
        int index = 0;
        while (index < command.size())
        {
            if (command[index] == 'G')
            {
                result += 'G';
                index += 1;
            }
            else
            {
                if (command[index + 1] == ')')
                {
                    result += "o";
                    index += 2;
                }
                else
                {
                    result += "al";
                    index += 4;
                }
            }
        }
        return result;
    }
};