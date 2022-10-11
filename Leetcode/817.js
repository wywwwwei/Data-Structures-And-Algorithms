/**
 * 817. 链表组件
 * link：https://leetcode.cn/problems/linked-list-components/
 */

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number[]} nums
 * @return {number}
 */
var numComponents = function (head, nums) {
    const numsSet = new Set(nums);

    let node = head;
    let result = 0;
    let inSeq = false;
    while (node) {
        if (numsSet.has(node.val)) {
            if (!inSeq) {
                result += 1;
                inSeq = true;
            }
        } else {
            inSeq = false;
        }
        node = node.next;
    }

    return result;
};