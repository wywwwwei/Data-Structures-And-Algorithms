/**
 * 1678. 设计 Goal 解析器
 * link：https://leetcode.cn/problems/goal-parser-interpretation/
 */

/**
 * @param {string} command
 * @return {string}
 */
var interpret = function (command) {
    // return command.replaceAll("()", "o").replaceAll("(al)", "al");
    const n = command.length;
    let result = "";
    let index = 0;
    while (index < n) {
        if (command[index] === "G") {
            result += "G";
            index += 1;
        } else {
            if (command[index + 1] === ")") {
                result += "o";
                index += 2;
            } else {
                result += "al";
                index += 4;
            }
        }
    }
    return result;
};