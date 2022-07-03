/**
 * 1200. 最小绝对差
 * link：https://leetcode.cn/problems/minimum-absolute-difference/
 */

/**
 * @param {number[]} arr
 * @return {number[][]}
 */
var minimumAbsDifference = function (arr) {
    arr.sort((a, b) => (a - b));

    let min_diff = Number.MAX_VALUE;
    let answer = [];
    for (let i = 0; i < arr.length - 1; i++) {
        let diff = arr[i + 1] - arr[i];
        if (diff < min_diff) {
            min_diff = diff;
            answer = [];
            answer.push([arr[i], arr[i + 1]]);
        } else if (diff == min_diff) {
            answer.push([arr[i], arr[i + 1]]);
        }
    }

    return answer;
};