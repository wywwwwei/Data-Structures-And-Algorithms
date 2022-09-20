/**
 * 854. 相似度为 K 的字符串
 * link：https://leetcode.cn/problems/k-similar-strings/
 */

/**
 * @param {string} s1
 * @param {string} s2
 * @return {number}
 */
var kSimilarity = function (s1, s2) {
    const n = s1.length;
    if (n <= 1) {
        return 0;
    }
    let str1 = "", str2 = "";
    for (let i = 0; i < n; i++) {
        if (s1[i] !== s2[i]) {
            str1 += s1[i];
            str2 += s2[i];
        }
    }
    const diffN = str1.length;
    if (diffN === 0) {
        return 0;
    }

    const swap = function (str, i, j) {
        const strArray = [...str];
        const c = strArray[i];
        strArray[i] = strArray[j];
        strArray[j] = c;
        return strArray.join('');
    };

    const minSwap = (s1, s2, pos) => {
        // 最好情况每两个都能相互交换时的次数
        let swapTimes = 0;
        for (let i = pos; i < s1.length; i++) {
            swapTimes += s1[i] !== s2[i] ? 1 : 0;
        }
        return Math.floor((swapTimes + 1) / 2);
    }

    let result = diffN - 1;
    const dfs = function (index, currentSwap, str1, str2) {
        // 已经超出当前最好结果
        if (currentSwap > result) {
            return;
        }
        // 上次更换后可能可以往前推进
        while (index < diffN && str1[index] === str2[index]) {
            index++;
        }
        if (index >= diffN) {
            result = Math.min(result, currentSwap);
            return;
        }
        // 最少交换情况下都超出当前最好结果
        if (currentSwap + minSwap(str1, str2, index) >= result) {
            return;
        }
        for (let i = index + 1; i < diffN; i++) {
            if (str1[i] === str2[index]) {
                const nextStr1 = swap(str1, index, i);
                dfs(index + 1, currentSwap + 1, nextStr1, str2);
            }
        }
    }

    dfs(0, 0, str1, str2);
    return result;
};