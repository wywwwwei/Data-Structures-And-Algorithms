/**
 * 1710. 卡车上的最大单元数
 * link：https://leetcode.cn/problems/maximum-units-on-a-truck/
 */

/**
 * @param {number[][]} boxTypes
 * @param {number} truckSize
 * @return {number}
 */
var maximumUnits = function (boxTypes, truckSize) {
    const sortBox = boxTypes.sort((a, b) => (b[1] - a[1] || a[0] - b[0]));

    let result = 0;
    let index = 0;
    while (truckSize > 0 && index < sortBox.length) {
        const num = Math.min(truckSize, sortBox[index][0]);
        result += num * sortBox[index][1];
        truckSize -= num;
        index++;
    }

    return result;
};