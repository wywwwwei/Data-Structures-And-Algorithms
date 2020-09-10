# 78. 子集 Cascading
# link：https://leetcode-cn.com/problems/subsets/

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result: List[List[int]] = []
        result.append([])

        for num in nums:
            for i in range(0, len(result)):
                result.append(result[i]+[num])

        return result
