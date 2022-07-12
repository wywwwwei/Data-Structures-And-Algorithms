/**
 * 735. 行星碰撞
 * link：https://leetcode.cn/problems/asteroid-collision/
 */

/**
 * @param {number[]} asteroids
 * @return {number[]}
 */
var asteroidCollision = function (asteroids) {
    const stack = [];
    for (const asteroid of asteroids) {
        if (asteroid > 0) {
            stack.push(asteroid);
        } else {
            const val = - asteroid;
            let alive = true;
            for (let i = stack.length - 1; i >= 0; i--) {
                if (!alive || stack[i] < 0) { 
                    break;
                }
                // update alive after this collision
                alive = val > stack[i];
                if (val >= stack[i]) {
                    stack.pop();
                }
            }
            if (alive) {
                stack.push(asteroid);
            }
        }
    }
    return stack;
};