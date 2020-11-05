/**
 * 1356. 根据数字二进制下 1 的数目排序
 * link：https://leetcode-cn.com/problems/sort-integers-by-the-number-of-1-bits/
 */

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        // unordered_map<int, int> bit_count;
        // for (const int &a : arr)
        // {
        //     bit_count[a] = bitset<16>(a).count();
        // }

        // int bit_count[10001];
        // for (int i = 0; i < 10001; i++)
        //     bit_count[i] = bit_count[i >> 1] + (i & 1);

        sort(arr.begin(), arr.end(), [](const int &a, const int &b) {
            return make_pair(bitset<16>(a).count(), a) < make_pair(bitset<16>(b).count(), b);
        });
        return arr;
    }
};