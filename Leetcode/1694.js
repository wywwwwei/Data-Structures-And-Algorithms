/**
 * 1694. 重新格式化电话号码
 * link：https://leetcode.cn/problems/reformat-phone-number/
 */

/**
 * @param {string} number
 * @return {string}
 */
var reformatNumber = function (number) {
    const formatNumber = number.replaceAll(" ", "").replaceAll("-", "");
    const n = formatNumber.length;
    let result = "";
    let index = 0;
    for (index = 0; index < n - 4; index += 3) {
        result += formatNumber.substring(index, index + 3) + "-";
    }
    switch (n - index) {
        case 2:
        case 3:
            result += formatNumber.substring(index, n);
            break;
        case 4:
            result += formatNumber.substring(index, index + 2) + "-" + formatNumber.substring(index + 2, index + 4);
            break;
    }
    return result;
};