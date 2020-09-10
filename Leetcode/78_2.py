# 78. 子集 Binary Sorted
# link：https://leetcode-cn.com/problems/subsets/

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result: List[List[int]] = []

        n = len(nums)
        padding = 1 << n

        for i in range(2**n):
            bit_mask = bin(padding | i)[3:]
            result.append([nums[j] for j in range(n) if bit_mask[j] == '1'])

        return result
