/**
 * 952. 按公因数计算最大组件大小
 * link：https://leetcode.cn/problems/largest-component-size-by-common-factor/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var largestComponentSize = function (nums) {
    const m = Math.max(...nums);
    const uf = new UnionFind(m + 1);
    for (const num of nums) {
        for (let i = 2; i * i <= num; i++) {
            if (num % i === 0) {
                uf.union(num, i);
                uf.union(num, Math.floor(num / i));
            }
        }
    }

    const counts = new Array(m + 1).fill(0);
    let ans = 0;
    for (let num of nums) {
        const root = uf.find(num);
        counts[root]++;
        ans = Math.max(ans, counts[root]);
    }
    return ans;
};

class UnionFind {
    constructor(n) {
        this.parent = new Array(n).fill(0).map((_, i) => i);
        this.rank = new Array(n).fill(0);
    }

    union(x, y) {
        let rootX = this.find(x);
        let rootY = this.find(y);
        if (rootX === rootY) {
            return;
        }
        if (this.rank[rootX] > this.rank[rootY]) {
            this.parent[rootY] = rootX;
        } else if (this.rank[rootX] < this.rank[rootY]) {
            this.parent[rootX] = rootY;
        } else {
            this.parent[rootY] = rootX;
            this.rank[rootX]++;
        }
    }

    find(x) {
        if (this.parent[x] !== x) {
            this.parent[x] = this.find(this.parent[x]);
        }
        return this.parent[x];
    }
};