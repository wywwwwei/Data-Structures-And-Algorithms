/**
 * 816. 模糊坐标
 * link：https://leetcode.cn/problems/ambiguous-coordinates/
 */

/**
 * @param {string} s
 * @return {string[]}
 */
var ambiguousCoordinates = function (s) {
    const parse = function (str) {
        const parseResult = [];
        const n = str.length;
        if (str[0] !== '0' || str === "0") {
            parseResult.push(str);
        }
        if (str[n - 1] === '0') {
            return parseResult;
        }
        for (let i = 1; i < n; ++i) {
            if (i !== 1 && str[0] === '0') {
                continue;
            }
            parseResult.push(str.slice(0, i) + "." + str.slice(i));
        }
        return parseResult;
    }
    const result = [];
    s = s.slice(1, s.length - 1);
    const n = s.length;
    for (let i = 1; i < n; ++i) {
        const left = parse(s.slice(0, i));
        if (left.length === 0) {
            continue;
        }
        const right = parse(s.slice(i));
        if (right.length === 0) {
            continue;
        }
        for (const l of left) {
            for (const r of right) {
                result.push("(" + l + ", " + r + ")");
            }
        }
    }
    return result;
};