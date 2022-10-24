/**
 * 934. 最短的桥
 * link：https://leetcode.cn/problems/shortest-bridge/
 */

/**
 * @param {number[][]} grid
 * @return {number}
 */
var shortestBridge = function (grid) {
    const n = grid.length;
    const steps = [[-1, 0], [0, -1], [1, 0], [0, 1]];

    // find first island
    let queue = [];
    const findFirstLand = function () {
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                if (grid[i][j] === 1) {
                    return [i, j];
                }
            }
        }
        return null;
    }
    const firstCell = findFirstLand();
    grid[firstCell[0]][firstCell[1]] = -1;
    queue.push(firstCell);

    const island = [];
    while (queue.length > 0) {
        const cell = queue.shift();
        island.push(cell);
        for (let i = 0; i < 4; i++) {
            let dx = cell[0] + steps[i][0];
            let dy = cell[1] + steps[i][1];
            if (dx >= 0 && dy >= 0 && dx < n && dy < n && grid[dx][dy] === 1) {
                queue.push([dx, dy]);
                grid[dx][dy] = -1;
            }
        }
    }
    // Spread out
    let step = 0;
    queue = [...island];
    while (queue.length > 0) {
        const size = queue.length;
        for (let i = 0; i < size; i++) {
            const cell = queue.shift();
            for (let j = 0; j < 4; j++) {
                const dx = cell[0] + steps[j][0];
                const dy = cell[1] + steps[j][1];
                if (dx >= 0 && dy >= 0 && dx < n && dy < n) {
                    if (grid[dx][dy] === 0) {
                        queue.push([dx, dy]);
                        grid[dx][dy] = -1;
                    } else if (grid[dx][dy] === 1) {
                        return step;
                    }
                }
            }
        }
        step++;
    }
    return 0;
};