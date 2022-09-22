/**
 * 707. 设计链表
 * link：https://leetcode.cn/problems/design-linked-list/
 */

class ListNode {
    constructor(val, next = null) {
        this.val = val;
        this.next = next;
    }
};

var MyLinkedList = function () {
    this.size = 0;
    this.head = new ListNode(0);
};

/** 
 * @param {number} index
 * @return {number}
 */
MyLinkedList.prototype.get = function (index) {
    if (index < 0 || index >= this.size) {
        return -1;
    }
    let node = this.head;
    for (let i = 0; i <= index; i++) {
        node = node.next;
    }
    return node.val;
};

/** 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtHead = function (val) {
    this.addAtIndex(0, val);
};

/** 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtTail = function (val) {
    this.addAtIndex(this.size, val);
};

/** 
 * @param {number} index 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtIndex = function (index, val) {
    if (index > this.size) {
        return;
    }
    index = Math.max(0, index);
    this.size++;
    let node = this.head;
    for (let i = 0; i < index; i++) {
        node = node.next;
    }
    const newNode = new TreeNode(val);
    newNode.next = node.next;
    node.next = newNode;
};

/** 
 * @param {number} index
 * @return {void}
 */
MyLinkedList.prototype.deleteAtIndex = function (index) {
    if (index < 0 || index >= this.size) {
        return;
    }
    this.size--;
    let node = this.head;
    for (let i = 0; i < index; i++) {
        node = node.next;
    }
    node.next = node.next.next;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * var obj = new MyLinkedList()
 * var param_1 = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index,val)
 * obj.deleteAtIndex(index)
 */