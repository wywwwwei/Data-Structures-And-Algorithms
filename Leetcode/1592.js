/**
 * 1592. 重新排列单词间的空格
 * link：https://leetcode.cn/problems/rearrange-spaces-between-words/
 */

/**
 * @param {string} text
 * @return {string}
 */
var reorderSpaces = function (text) {
    const n = text.length;
    let characterCount = 0;
    const words = text.split(" ").filter((value) => {
        characterCount += value.length;
        return value.length > 0;
    });
    const wordCount = words.length;
    const spaceCount = n - characterCount;
    let space, last;
    if (wordCount === 1) {
        space = 0;
        last = spaceCount;
    } else {
        space = Math.floor(spaceCount / (wordCount - 1));
        last = spaceCount % (wordCount - 1);
    }
    return words.join(" ".repeat(space)) + " ".repeat(last);
};