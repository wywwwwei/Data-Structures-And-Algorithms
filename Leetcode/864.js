/**
 * 864. 获取所有钥匙的最短路径
 * link：https://leetcode.cn/problems/shortest-path-to-get-all-keys/
 */

/**
 * @param {string[]} grid
 * @return {number}
 */
var shortestPathAllKeys = function (grid) {
    const m = grid.length, n = grid[0].length;
    const keys = new Map();

    let startX, startY;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === '@') {
                startX = i, startY = j;
            } else if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                keys.set(grid[i][j], keys.size);
            }
        }
    }

    const steps = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    const queue = [[startX, startY, 0]];
    const store = new Array(m).fill(null).map(() => new Array(n).fill(0).map(() => new Array(1 << keys.size).fill(-1)));
    store[startX][startY][0] = 0;
    while (queue.length) {
        let [x, y, mask] = queue.shift();
        for (let i = 0; i < 4; i++) {
            let dx = x + steps[i][0], dy = y + steps[i][1];
            if (dx >= 0 && dx < m && dy >= 0 && dy < n && grid[dx][dy] !== '#') {
                if (grid[dx][dy] === '.' || grid[dx][dy] === '@') {
                    if (store[dx][dy][mask] === -1) {
                        store[dx][dy][mask] = store[x][y][mask] + 1;
                        queue.push([dx, dy, mask]);
                    }
                } else if (grid[dx][dy] >= 'a' && grid[dx][dy] <= 'z') {
                    const key = keys.get(grid[dx][dy]);
                    if (store[dx][dy][mask | (1 << key)] === -1) {
                        store[dx][dy][mask | (1 << key)] = store[x][y][mask] + 1;
                        if ((mask | (1 << key)) === (1 << keys.size) - 1) {
                            return store[dx][dy][mask | (1 << key)];
                        }
                        queue.push([dx, dy, mask | (1 << key)]);
                    }
                } else {
                    const key = keys.get(grid[dx][dy].toLowerCase());
                    if ((mask & (1 << key)) !== 0 && store[dx][dy][mask] === -1) {
                        store[dx][dy][mask] = store[x][y][mask] + 1;
                        queue.push([dx, dy, mask]);
                    }
                }
            }
        }
    }
    return -1;
};