/**
 * 1184. 公交站间的距离
 * link：https://leetcode.cn/problems/distance-between-bus-stops/
 */

/**
 * @param {number[]} distance
 * @param {number} start
 * @param {number} destination
 * @return {number}
 */
var distanceBetweenBusStops = function (distance, start, destination) {
    let leftDistance = 0, rightDistance = 0;
    const n = distance.length;
    for (let i = start; i != destination; i = (i + 1) % n) {
        leftDistance += distance[i];
    }
    for (let i = (start + n - 1) % n; i != (destination + n - 1) % n; i = (i + n - 1) % n) {
        rightDistance += distance[i];
    }
    return Math.min(leftDistance, rightDistance);
};