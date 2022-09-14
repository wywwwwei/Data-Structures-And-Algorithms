/**
 * 672. 灯泡开关 Ⅱ
 * link：https://leetcode.cn/problems/bulb-switcher-ii/
 */

/**
 * @param {number} n
 * @param {number} presses
 * @return {number}
 */
var flipLights = function (n, presses) {
    switch (n) {
        case 0:
            return 0;
        case 1:
            return (presses > 0) + 1;
        case 2:
            return (presses > 1) + (presses > 0) * 2 + 1;
    }
    switch (presses) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 7;
    }
    return 8;
};