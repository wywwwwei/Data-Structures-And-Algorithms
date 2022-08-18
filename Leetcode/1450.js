/**
 * 1450. 在既定时间做作业的学生人数
 * link：https://leetcode.cn/problems/number-of-students-doing-homework-at-a-given-time/
 */

/**
 * @param {number[]} startTime
 * @param {number[]} endTime
 * @param {number} queryTime
 * @return {number}
 */
var busyStudent = function (startTime, endTime, queryTime) {
    const n = startTime.length;
    let result = 0;
    for (let i = 0; i < n; i++) {
        if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
            result++;
        }
    }
    return result;
};