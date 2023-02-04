/**
 * NC61 两数之和
 * link：https://www.nowcoder.com/practice/20ef0972485e41019e39543e8e895b7f
 */

#include <bits/stdc++.h>
#include <cstddef>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
    /**
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // write code here
        unordered_map<int, int> store;
        for (int i = 1; i <= numbers.size(); ++i)
        {
            int number = numbers[i - 1];
            if (store.find(target - number) != store.end())
            {
                return {store[target - number], i};
            }
            store[number] = i;
        }
        return {};
    }
};