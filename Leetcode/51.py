# 51. N 皇后
# link：https://leetcode-cn.com/problems/n-queens/

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        result = []
        path = [-1] * n
        row = ["."] * n

        def generateBoard() -> List[str]:
            board = list()
            for i in range(n):
                row[path[i]] = "Q"
                board.append("".join(row))
                row[path[i]] = "."
            return board

        def solve(row: int, columns: int, left_diag: int, right_diag: int):
            if row == n:
                result.append(generateBoard())
            else:
                all_pos = ((1 << n)-1) & (~(columns | left_diag | right_diag))

                while all_pos != 0:
                    pos = all_pos & (-all_pos)
                    all_pos = all_pos & (all_pos - 1)
                    col = bin(pos-1).count("1")
                    path[row] = col
                    solve(row+1, columns | pos, (left_diag | pos)
                          >> 1, (right_diag | pos) << 1)

        solve(0, 0, 0, 0)
        return result
