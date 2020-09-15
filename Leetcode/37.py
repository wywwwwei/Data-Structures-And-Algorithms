# 37. 解数独 状态压缩+回溯
# link：https://leetcode-cn.com/problems/sudoku-solver/

class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row = [0] * 9
        col = [0] * 9
        block = [[0]*3 for _ in range(3)]
        all_pos = []

        def reversePos(i: int, j: int, val: int):
            row[i] ^= 1 << val
            col[j] ^= 1 << val
            block[i//3][j//3] ^= 1 << val

        def dfs(index: int) -> bool:
            if index == len(all_pos):
                return True

            i, j = all_pos[index]
            selection = 0x1FF & (~(row[i] | col[j] | block[i//3][j//3]))
            while selection != 0:
                cur_select = selection & (-selection)
                selection = selection & (selection - 1)
                fill_val = bin(cur_select).count('0') - 1

                reversePos(i, j, fill_val)
                board[i][j] = str(fill_val + 1)
                if dfs(index+1):
                    return True
                reversePos(i, j, fill_val)

        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    all_pos.append((i, j))
                else:
                    reversePos(i, j, int(board[i][j])-1)
        dfs(0)
