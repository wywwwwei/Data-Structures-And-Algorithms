# 面试题 08.07. 无重复字符串的排列组合 深搜
# https://leetcode-cn.com/problems/permutation-i-lcci/

class Solution:
    def permutation(self, S: str) -> List[str]:
        result: List[str] = []
        n = len(S)

        def dfs(unused: str, path: str):
            if unused == '':
                result.append(path)
                return

            for i in range(len(unused)):
                dfs(unused[:i]+unused[i+1:], path+unused[i])

        dfs(S, '')
        return result
