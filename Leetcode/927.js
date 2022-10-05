/**
 * 927. 三等分
 * link：https://leetcode.cn/problems/three-equal-parts/
 */

/**
 * @param {number[]} arr
 * @return {number[]}
 */
var threeEqualParts = function (arr) {
    const sum = arr.reduce((prev, cur) => (prev + cur));
    if (sum % 3 !== 0) {
        return [-1, -1];
    }
    if (sum === 0) {
        return [0, 2];
    }

    const n = arr.length;
    const targetOneCount = sum / 3;
    let leftIndex = 0, midIndex = 0, rightIndex = 0;
    let oneCount = 0;
    for (let i = 0; i < n; i++) {
        if (arr[i] === 0) {
            continue;
        }
        if (oneCount === 0) {
            leftIndex = i;
        } else if (oneCount === targetOneCount) {
            midIndex = i;
        } else if (oneCount === 2 * targetOneCount) {
            rightIndex = i;
        }
        oneCount++;
    }

    let minLen = n - rightIndex;
    if (leftIndex + minLen > midIndex || midIndex + minLen > rightIndex) {
        return [-1, -1];
    }
    for (let i = 0; i < minLen; i++) {
        if (arr[leftIndex + i] !== arr[midIndex + i] || arr[leftIndex + i] !== arr[rightIndex + i]) {
            return [-1, -1];
        }
    }
    return [leftIndex + minLen - 1, midIndex + minLen];
};