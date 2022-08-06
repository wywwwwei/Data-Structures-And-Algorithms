/**
 * 636. 函数的独占时间
 * link：https://leetcode.cn/problems/exclusive-time-of-functions/
 */

/**
 * @param {number} n
 * @param {string[]} logs
 * @return {number[]}
 */
var exclusiveTime = function (n, logs) {
    const result = new Array(n).fill(0);
    const stack = [];
    for (const log of logs) {
        let [id, tag, time] = log.split(':');
        time = parseInt(time, 10);
        if (tag === "start") {
            if (stack.length > 0) {
                result[stack[stack.length - 1][0]] += time - stack[stack.length - 1][1];
                stack[stack.length - 1][1] = time;
            }
            stack.push([id, time]);
        } else {
            const process = stack.pop();
            result[process[0]] += time - process[1] + 1;
            if (stack.length) {
                stack[stack.length - 1][1] = time + 1;
            }
        }
    }
    return result;
};