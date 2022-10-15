/**
 * 886. 可能的二分法
 * link：https://leetcode.cn/problems/possible-bipartition/
 */

/**
 * @param {number} n
 * @param {number[][]} dislikes
 * @return {boolean}
 */
var possibleBipartition = function (n, dislikes) {
    const graph = new Array(n + 1).fill(null).map(() => []);
    const color = new Array(n + 1).fill(0);
    const redColor = 1, blueColor = 2;

    for (const dislike of dislikes) {
        graph[dislike[0]].push(dislike[1]);
        graph[dislike[1]].push(dislike[0]);
    }

    const dfs = (index, targetColor) => {
        color[index] = targetColor;
        for (const node of graph[index]) {
            if (color[node] !== 0 && color[index] === color[node]) {
                return false;
            }
            if (color[node] === 0 && !dfs(node, targetColor === redColor ? blueColor : redColor)) {
                return false;
            }
        }
        return true;
    }

    for (let i = 1; i <= n; i++) {
        if (color[i] === 0 && !dfs(i, redColor)) {
            return false;
        }
    }

    return true;
};