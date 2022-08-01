/**
 * 622. 设计循环队列 (链表)
 * link：https://leetcode.cn/problems/design-circular-queue/
 */

/**
 * @param {number} k
 */
var MyCircularQueue = function (k) {
    this.capacity = k;
    this.size = 0;
    this.head = null;
    this.tail = null;
};

/** 
 * @param {number} value
 * @return {boolean}
 */
MyCircularQueue.prototype.enQueue = function (value) {
    if (this.isFull()) {
        return false;
    }
    this.size++;
    const node = new ListNode(value);
    if (this.head) {
        this.tail.next = node;
        this.tail = node;
    } else {
        this.head = node;
        this.tail = node;
    }
    return true;
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.deQueue = function () {
    if (this.isEmpty()) {
        return false;
    }
    this.size--;
    this.head = this.head.next;
    return true;
};

/**
 * @return {number}
 */
MyCircularQueue.prototype.Front = function () {
    return this.isEmpty() ? -1 : this.head.val;
};

/**
 * @return {number}
 */
MyCircularQueue.prototype.Rear = function () {
    return this.isEmpty() ? -1 : this.tail.val;
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.isEmpty = function () {
    return this.size === 0;
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.isFull = function () {
    return this.size === this.capacity;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * var obj = new MyCircularQueue(k)
 * var param_1 = obj.enQueue(value)
 * var param_2 = obj.deQueue()
 * var param_3 = obj.Front()
 * var param_4 = obj.Rear()
 * var param_5 = obj.isEmpty()
 * var param_6 = obj.isFull()
 */