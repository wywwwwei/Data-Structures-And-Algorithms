# 47. 全排列 II 回溯
# link：https://leetcode-cn.com/problems/permutations-ii/

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        n: int = len(nums)
        result = []
        path = []
        visited = [False for _ in range(n)]

        def backtrace():
            if len(path) == n:
                result.append(path.copy())
                return
            for i in range(n):
                if visited[i]:
                    continue
                if i > 0 and nums[i] == nums[i-1] and not visited[i-1]:
                    continue
                visited[i] = True
                path.append(nums[i])
                backtrace()
                path.pop()
                visited[i] = False

        nums.sort()
        backtrace()
        return result
