/**
 * 745. 前缀和后缀搜索
 * link：https://leetcode.cn/problems/prefix-and-suffix-search/
 */

/**
 * @param {string[]} words
 */
var WordFilter = function (words) {
    this.store = new Map();
    for (let i = 0; i < words.length; i++) {
        const word = words[i];
        const n = word.length;
        for (let prefixLength = 1; prefixLength <= n; prefixLength++) {
            for (let suffixLength = 1; suffixLength <= n; suffixLength++) {
                this.store.set(word.substring(0, prefixLength) + "#" + word.substring(n - suffixLength), i);
            }
        }
    }
};

/** 
 * @param {string} pref 
 * @param {string} suff
 * @return {number}
 */
WordFilter.prototype.f = function (pref, suff) {
    const key = pref + "#" + suff;
    return this.store.has(key) ? this.store.get(key) : -1;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * var obj = new WordFilter(words)
 * var param_1 = obj.f(pref,suff)
 */