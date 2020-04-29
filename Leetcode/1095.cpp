/**
 * 1095. 山脉数组中查找目标值
 * link：https://leetcode-cn.com/problems/find-in-mountain-array/ 
 */

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
private:
    int binarySearch(const function<bool(int)> &determine, const function<bool(int)> &ifLeft, int left, int right)
    {
        if (left > right)
            return -1;

        int mid = left + (right - left) / 2;
        if (determine(mid))
            return mid;

        else if (ifLeft(mid))
            return binarySearch(determine, ifLeft, left, mid - 1);
        else
            return binarySearch(determine, ifLeft, mid + 1, right);
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int buf_i, buf_i_1;
        int highest = binarySearch(
            [&mountainArr, &buf_i, &buf_i_1](int i) -> bool {
                buf_i = mountainArr.get(i);
                buf_i_1 = mountainArr.get(i + 1);
                return i > 0 && i < mountainArr.length() - 1 && buf_i > mountainArr.get(i - 1) && buf_i > buf_i_1;
            },
            [&mountainArr, &buf_i, &buf_i_1](int i) -> bool {
                return buf_i > buf_i_1;
            },
            0, mountainArr.length() - 1);
        if (mountainArr.get(highest) == target)
            return highest;

        bool increase = true;
        auto determine = [&mountainArr, &target](int i) -> bool {
            return mountainArr.get(i) == target;
        };
        auto ifLeft = [&mountainArr, &target, &increase](int i) -> bool {
            return increase ? mountainArr.get(i) > target : mountainArr.get(i) < target;
        };

        int indexLeft = binarySearch(determine, ifLeft, 0, highest - 1);
        increase = false;
        int indexRight = binarySearch(determine, ifLeft, highest + 1, mountainArr.length() - 1);

        return indexLeft == -1 ? indexRight : indexLeft;
    }
};