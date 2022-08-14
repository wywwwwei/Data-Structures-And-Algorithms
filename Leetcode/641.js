/**
 * 641. 设计循环双端队列
 * link：https://leetcode.cn/problems/design-circular-deque/
 */

class Node {
    constructor(val, prev = null, next = null) {
        this.val = val;
        this.prev = prev;
        this.next = next;
    }
};

/**
 * @param {number} k
 */
var MyCircularDeque = function (k) {
    this.capacity = k;
    this.size = 0;

    this.head = null;
    this.tail = null;
};

/** 
 * @param {number} value
 * @return {boolean}
 */
MyCircularDeque.prototype.insertFront = function (value) {
    if (this.isFull()) {
        return false;
    }
    const node = new Node(value);
    if (!this.head) {
        this.tail = node;
    } else {
        node.next = this.head;
        this.head.prev = node;
    }
    this.head = node;
    this.size++;
    return true;
};

/** 
 * @param {number} value
 * @return {boolean}
 */
MyCircularDeque.prototype.insertLast = function (value) {
    if (this.isFull()) {
        return false;
    }
    const node = new Node(value);
    if (!this.tail) {
        this.head = node;
    } else {
        node.prev = this.tail;
        this.tail.next = node;
    }
    this.tail = node;
    this.size++;
    return true;
};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.deleteFront = function () {
    if (this.isEmpty()) {
        return false;
    }
    this.head = this.head.next;
    if (!this.head) {
        this.tail = null;
    } else {
        this.head.prev = null;
    }
    this.size--;
    return true;
};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.deleteLast = function () {
    if (this.isEmpty()) {
        return false;
    }
    this.tail = this.tail.prev;
    if (!this.tail) {
        this.head = null;
    } else {
        this.tail.next = null;
    }
    this.size--;
    return true;
};

/**
 * @return {number}
 */
MyCircularDeque.prototype.getFront = function () {
    if (this.isEmpty()) {
        return -1;
    }
    return this.head.val;
};

/**
 * @return {number}
 */
MyCircularDeque.prototype.getRear = function () {
    if (this.isEmpty()) {
        return -1;
    }
    return this.tail.val;
};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.isEmpty = function () {
    return this.size === 0;
};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.isFull = function () {
    return this.size === this.capacity;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * var obj = new MyCircularDeque(k)
 * var param_1 = obj.insertFront(value)
 * var param_2 = obj.insertLast(value)
 * var param_3 = obj.deleteFront()
 * var param_4 = obj.deleteLast()
 * var param_5 = obj.getFront()
 * var param_6 = obj.getRear()
 * var param_7 = obj.isEmpty()
 * var param_8 = obj.isFull()
 */