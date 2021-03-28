/**
 * 190. 颠倒二进制位
 * link：https://leetcode-cn.com/problems/reverse-bits/
 */

class Solution
{
    const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
    const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
    const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
    const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111

public:
    uint32_t reverseBits(uint32_t n)
    {
        // string result(bitset<32>(n).to_string());
        // reverse(result.begin(),result.end());
        // return bitset<32>(result).to_ulong();

        // uint32_t result = 0;
        // for (int i = 0; i < 32 && n > 0; ++i)
        // {
        //     result |= (n & 1) << (31 - i);
        //     n >>= 1;
        // }
        // return result;

        n = n >> 1 & M1 | (n & M1) << 1;
        n = n >> 2 & M2 | (n & M2) << 2;
        n = n >> 4 & M4 | (n & M4) << 4;
        n = n >> 8 & M8 | (n & M8) << 8;
        return n >> 16 | n << 16;
    }
};