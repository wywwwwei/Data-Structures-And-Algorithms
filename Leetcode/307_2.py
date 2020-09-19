# 307. 区域和检索 - 数组可修改 线段树(数组实现)
# link：https://leetcode-cn.com/problems/range-sum-query-mutable/

class NumArray:
    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.store = [0] * self.n + nums

        for i in range(self.n-1, 0, -1):
            self.store[i] = self.store[2 * i] + self.store[2 * i + 1]

    def update(self, i: int, val: int) -> None:
        i += self.n

        diff: int = val - self.store[i]
        while i > 0:
            self.store[i] += diff
            i = i // 2

    def sumRange(self, i: int, j: int) -> int:
        i += self.n
        j += self.n
        sum: int = 0

        while i <= j:
            if i % 2 == 1:
                sum += self.store[i]
                i += 1
            if j % 2 == 0:
                sum += self.store[j]
                j -= 1
            i = i // 2
            j = j // 2

        return sum
