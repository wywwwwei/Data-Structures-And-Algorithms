/**
 * 1417. 重新格式化字符串
 * link：https://leetcode.cn/problems/reformat-the-string/
 */

/**
 * @param {string} s
 * @return {string}
 */
var reformat = function (s) {
    let digitStr = "", letterStr = "";
    const isDigit = (ch) => (ch >= "0" && ch <= "9");
    for (const ch of s) {
        if (isDigit(ch)) {
            digitStr += ch;
        } else {
            letterStr += ch;
        }
    }

    let longStr = digitStr, shortStr = letterStr;
    if (longStr.length < shortStr.length) {
        [longStr, shortStr] = [shortStr, longStr];
    }

    if (longStr.length - shortStr.length > 1) {
        return "";
    }
    let result = "";
    for (let i = 0; i < longStr.length; i++) {
        result += longStr[i];
        if (i < shortStr.length) {
            result += shortStr[i];
        }
    }
    return result;
};