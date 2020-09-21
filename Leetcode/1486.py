# 1486. 数组异或操作 模拟
# link：https://leetcode-cn.com/problems/xor-operation-in-an-array/

class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        result: int = 0
        cur: int = start
        for _ in range(n):
            result ^= cur
            cur += 2
        return result
