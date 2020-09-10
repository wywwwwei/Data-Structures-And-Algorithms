# 216. 组合总和 III 深搜(回溯) + 剪枝
# link：https://leetcode-cn.com/problems/combination-sum-iii/

class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        result = []
        path = []

        def dfs(begin: int, target: int):
            if len(path) == k:
                if target == 0:
                    result.append(path.copy())
                return

            if target <= 0:
                return

            for i in range(begin, 10):
                path.append(i)
                dfs(i+1, target-i)
                path.pop()

        dfs(1, n)
        return result
