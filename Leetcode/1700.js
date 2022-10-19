/**
 * 1700. 无法吃午餐的学生数量
 * link：https://leetcode.cn/problems/number-of-students-unable-to-eat-lunch/
 */

/**
 * @param {number[]} students
 * @param {number[]} sandwiches
 * @return {number}
 */
var countStudents = function (students, sandwiches) {
    const n = students.length;
    let oneCount = students.reduce((prev, cur) => (prev + cur));
    let zeroCount = n - oneCount;

    for (const sandwich of sandwiches) {
        if (sandwich === 0 && zeroCount > 0) {
            zeroCount--;
        } else if (sandwich === 1 && oneCount > 0) {
            oneCount--;
        } else {
            break;
        }
    }

    return zeroCount + oneCount;
};