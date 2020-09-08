# 77. 组合 深搜 + 剪枝
# link：https://leetcode-cn.com/problems/combinations/

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        if k == 0:
            return []
        elif k == 1:
            return [[i]for i in range(1, n+1)]
        elif k == n:
            return [[i for i in range(1, n+1)]]

        path = []
        result = []

        def dfs(begin: int):
            if len(path) == k:
                result.append(path.copy())
                return
            for i in range(begin, n - k + len(path)+2):
                path.append(i)
                dfs(i+1)
                path.pop(len(path)-1)

        dfs(1)
        return result
