# 39. 组合总和 深搜(回溯) + 剪枝
# link：https://leetcode.com/problems/combination-sum/

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        path = []
        result = []

        def dfs(begin: int, tg: int):
            if tg < 0:
                return
            elif tg == 0:
                result.append(path.copy())
                return

            for i in range(begin, len(candidates)):
                path.append(candidates[i])
                dfs(i, tg - candidates[i])
                path.pop()

        dfs(0, target)
        return result
