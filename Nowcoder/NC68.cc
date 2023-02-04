/**
 * NC68 跳台阶
 * link：https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4
 */

class Solution
{
  public:
    int jumpFloor(int number)
    {
        if (number <= 2)
        {
            return number;
        }
        return jumpFloor(number - 1) + jumpFloor(number - 2);
    }
};