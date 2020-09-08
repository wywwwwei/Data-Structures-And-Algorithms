# 1. 两数之和
# link：https://leetcode-cn.com/problems/two-sum/

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashset = dict()
        for idx, num in enumerate(nums):
            if (target - num) in hashset:
                return [hashset.get(target - num), idx]
            hashset[num] = idx
        return []
