# 684. 冗余连接 并查集
# link：https://leetcode-cn.com/problems/redundant-connection/

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n: int = len(edges)
        ancestor = [i for i in range(n+1)]

        def find(idx: int) -> int:
            if ancestor[idx] != idx:
                ancestor[idx] = find(ancestor[idx])
            return ancestor[idx]

        def merge(u: int, v: int):
            a: int = find(u)
            b: int = find(v)
            if a <= b:
                ancestor[b] = a
            else:
                ancestor[a] = b

        for i in range(n):
            if find(edges[i][0]) == find(edges[i][1]):
                result: int = i
            else:
                merge(edges[i][0], edges[i][1])

        return edges[result]
