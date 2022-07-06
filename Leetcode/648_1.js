/**
 * 648. 单词替换
 * link：https://leetcode.cn/problems/replace-words/
 */

/**
 * @param {string[]} dictionary
 * @param {string} sentence
 * @return {string}
 */
var replaceWords = function (dictionary, sentence) {
    const trie = new Trie();

    for (const word of dictionary) {
        buildTrie(trie, word);
    }

    const words = sentence.split(' ');
    for (let i = 0; i < words.length; i++) {
        words[i] = findRoot(trie, words[i]);
    }

    return words.join(' ');
};

/**
 * @param {Trie} trie
 * @param {string} word
 */
const buildTrie = function (trie, word) {
    let trieNode = trie;
    for (const c of word) {
        if (!trieNode.children.has(c)) {
            trieNode.children.set(c, new Trie());
        }
        trieNode = trieNode.children.get(c);
    }
    trieNode.children.set('#', new Trie());
}

/**
 * @param {Trie} trie
 * @param {string} word
 * @return {string}
 */
const findRoot = function (trie, word) {
    let trieNode = trie;
    for (let i = 0; i < word.length; i++) {
        const c = word[i];
        if (trieNode.children.has('#')) {
            return word.substring(0, i);
        }
        if (!trieNode.children.has(c)) {
            break;
        }
        trieNode = trieNode.children.get(c);
    }
    return word;
}

class Trie {
    constructor() {
        this.children = new Map();
    }
}