/**
 * 745. 前缀和后缀搜索
 * link：https://leetcode.cn/problems/prefix-and-suffix-search/
 */

/**
 * @param {string[]} words
 */
var WordFilter = function (words) {
    this.words = words;
};

/** 
 * @param {string} pref 
 * @param {string} suff
 * @return {number}
 */
WordFilter.prototype.f = function (pref, suff) {
    const words = this.words;
    const n = words.length;
    for (let i = n - 1; i >= 0; i--) {
        if (words[i].startsWith(pref) && words[i].endsWith(suff)) {
            return i;
        }
    }
    return -1;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * var obj = new WordFilter(words)
 * var param_1 = obj.f(pref,suff)
 */