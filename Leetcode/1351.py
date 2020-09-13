# 1351. 统计有序矩阵中的负数
# link：https://leetcode-cn.com/problems/count-negative-numbers-in-a-sorted-matrix/

# Interesting solution
# class Solution:
#     def countNegatives(self, grid: List[List[int]]) -> int:
#         return str(grid).count('-')

class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        m = len(grid)
        j = len(grid[0]) - 1
        i = 0

        result = 0
        while i < m and j >= 0:
            if grid[i][j] >= 0:
                i += 1
            else:
                result += m - i
                j -= 1

        return result