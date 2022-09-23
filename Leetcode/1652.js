/**
 * 1652. 拆炸弹
 * link：https://leetcode.cn/problems/defuse-the-bomb/
 */

/**
 * @param {number[]} code
 * @param {number} k
 * @return {number[]}
 */
var decrypt = function (code, k) {
    const n = code.length;
    const result = new Array(n).fill(0);
    if (k > 0) {
        let initValue = 0;
        for (let i = 0; i < k; i++) {
            initValue += code[i];
        }
        for (let i = 0, j = k; i < n; i++, j = (j + 1) % n) {
            initValue -= code[i];
            initValue += code[j];
            result[i] = initValue;
        }
    } else if (k < 0) {
        let initValue = 0;
        for (let i = n - 1; i > n - 1 + k; i--) {
            initValue += code[i];
        }
        for (let i = 0, j = n + k; i < n; i++, j = (j + 1) % n) {
            result[i] = initValue;
            initValue -= code[j];
            initValue += code[i];
        }
    }
    return result;
};