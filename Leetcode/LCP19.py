# LCP 19. 秋叶收藏集 DP
# link：https://leetcode-cn.com/problems/UlBDOe/

class Solution:
    def minimumOperations(self, leaves: str) -> int:
        r_turn: int = (1 if leaves[0] == 'y' else 0)
        y_turn: int = 10**5 + 1
        end_turn: int = 10**5+1

        for i in range(1, len(leaves)):
            if leaves[i] == 'r':
                end_turn = min(end_turn, y_turn)
                y_turn = min(y_turn, r_turn)+1
            else:
                end_turn = min(end_turn, y_turn)+1
                y_turn = min(y_turn, r_turn)
                r_turn += 1

        return end_turn
