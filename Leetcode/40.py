# 40. 组合总和 II 深搜(回溯) + 剪枝
# link：https://leetcode-cn.com/problems/combination-sum-ii/

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        path = []
        result = []

        def dfs(begin: int, tg: int):
            if tg < 0:
                return
            elif tg == 0:
                result.append(path.copy())
                return

            for i in range(begin, len(candidates)):
                if i > begin and candidates[i] == candidates[i-1]:
                    continue
                path.append(candidates[i])
                dfs(i+1, tg - candidates[i])
                path.pop()

        candidates.sort()
        dfs(0, target)
        return result
