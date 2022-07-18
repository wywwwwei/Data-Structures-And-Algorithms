/**
 * 871. 最低加油次数
 * link：https://leetcode.cn/problems/minimum-number-of-refueling-stops/
 */

/**
 * @param {number} target
 * @param {number} startFuel
 * @param {number[][]} stations
 * @return {number}
 */
var minRefuelStops = function (target, startFuel, stations) {
    const queue = new PriorityQueue((lhs, rhs) => (lhs - rhs));
    let answer = 0;
    for (const station of stations) {
        while (startFuel < station[0]) {
            if (queue.length() <= 0) {
                return -1;
            }
            startFuel += queue.pop();
            answer++;
        }
        queue.push(station[1]);
    }
    while (startFuel < target) {
        if (queue.length() <= 0) {
            return -1;
        }
        startFuel += queue.pop();
        answer++;
    }
    return answer;
};

class PriorityQueue {
    constructor(comparator) {
        this.store = [];
        this.comparator = comparator;
    }

    search(target) {
        let low = 0, high = this.store.length;
        while (low < high) {
            const mid = low + ((high - low) >> 1);
            if (this.comparator(this.store[mid], target) <= 0) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    push(element) {
        let index = this.search(element);
        this.store.splice(index, 0, element);
    }

    pop() {
        return this.store.pop();
    }

    length() {
        return this.store.length;
    }
};