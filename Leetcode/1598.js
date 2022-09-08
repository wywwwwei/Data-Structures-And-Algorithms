/**
 * 1598. 文件夹操作日志搜集器
 * link：https://leetcode.cn/problems/crawler-log-folder/
 */

/**
 * @param {string[]} logs
 * @return {number}
 */
var minOperations = function (logs) {
    let layer = 0;
    for (const log of logs) {
        if (log === "../") {
            layer = Math.max(0, layer - 1);
        } else if (log === "./") {
            continue;
        } else {
            layer++;
        }
    }
    return layer;
};