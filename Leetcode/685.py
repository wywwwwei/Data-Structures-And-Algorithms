# 685. 冗余连接 II 并查集
# link：https://leetcode-cn.com/problems/redundant-connection-ii/

class Solution:
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        n: int = len(edges)
        parent = [i for i in range(n+1)]
        ancestor = [i for i in range(n+1)]

        def find(idx: int) -> int:
            if ancestor[idx] != idx:
                ancestor[idx] = find(ancestor[idx])
            return ancestor[idx]

        def merge(u: int, v: int):
            ancestor[find(u)] = find(v)

        conflict: int = -1
        cycle: int = -1
        for idx in range(n):
            if parent[edges[idx][1]] != edges[idx][1]:
                conflict = idx
            else:
                parent[edges[idx][1]] = edges[idx][0]
                if find(edges[idx][0]) == find(edges[idx][1]):
                    cycle = idx
                else:
                    merge(edges[idx][0], edges[idx][1])

        if cycle < 0:
            return edges[conflict]

        if conflict < 0:
            return edges[cycle]

        return [parent[edges[conflict][1]], edges[conflict][1]]
