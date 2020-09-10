# 52. N皇后 II
# link：https://leetcode-cn.com/problems/n-queens-ii/

class Solution:
    def totalNQueens(self, n: int) -> int:
        count: int = 0

        def solve(row: int, columns: int, left_diag: int, right_diag: int):
            nonlocal count
            if row == n:
                count = count + 1
            else:
                all_pos = ((1 << n) - 1) & (~(columns |
                                              left_diag | right_diag))

                while all_pos != 0:
                    pos: int = all_pos & (-all_pos)
                    all_pos = all_pos & (all_pos - 1)
                    solve(row+1, columns | pos, (left_diag | pos)
                          >> 1, (right_diag | pos) << 1)

        solve(0, 0, 0, 0)
        return count
