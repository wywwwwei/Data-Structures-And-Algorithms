# 79. 单词搜索 回溯
# link：https://leetcode-cn.com/problems/word-search/

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n = len(board)
        m = len(board[0])
        size = len(word)
        move = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        visited = [[False for _ in range(m)] for _ in range(n)]

        def search(x: int, y: int, idx: int) -> bool:
            if idx == size - 1:
                return True

            visited[x][y] = True
            for val in move:
                dx = x + val[0]
                dy = y + val[1]
                if dx < 0 or dx >= n or dy < 0 or dy >= m:
                    continue
                if visited[dx][dy] or word[idx+1] != board[dx][dy]:
                    continue
                if search(dx, dy, idx+1):
                    return True

            visited[x][y] = False
            return False

        for i in range(n):
            for j in range(m):
                if board[i][j] == word[0]:
                    if search(i, j, 0):
                        return True

        return False
