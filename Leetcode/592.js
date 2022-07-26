/**
 * 592. 分数加减运算
 * link：https://leetcode.cn/problems/fraction-addition-and-subtraction/
 */

/**
 * @param {string} expression
 * @return {string}
 */
var fractionAddition = function (expression) {
    let index = 0;
    const n = expression.length;

    const parseNum = function () {
        let isNegative = false;
        let num = 0;
        if (expression[index] === '-') {
            isNegative = true;
            index++;
        } else if (expression[index] === '+') {
            index++;
        }
        while (index < n && isDigit(expression[index])) {
            num = num * 10 + (expression.charCodeAt(index) - '0'.charCodeAt(0));
            index++;
        }
        return isNegative ? - num : num;
    }

    let leftMolecular = 0, leftDenominator = 1;
    let rightMolecular = 0, rightDenominator = 0;

    while (index < n) {
        rightMolecular = parseNum();
        index++;
        rightDenominator = parseNum();
        [leftMolecular, leftDenominator] = addFraction(leftMolecular, leftDenominator, rightMolecular, rightDenominator);
        [leftMolecular, leftDenominator] = reduction(leftMolecular, leftDenominator);
        if (index >= n) {
            break;
        }
    }
    return leftMolecular + "/" + leftDenominator;
};

const isDigit = (element) => { return element >= '0' && element <= '9'; }

const addFraction = function (leftMolecular, leftDenominator, rightMolecular, rightDenominator) {
    return [leftMolecular * rightDenominator + leftDenominator * rightMolecular, leftDenominator * rightDenominator];
}

const gcd = function (a, b) {
    if (!b) {
        return a;
    }
    return gcd(b, a % b);
}

const reduction = function (molecular, denominator) {
    if (molecular === 0) {
        return [molecular, 1];
    } else {
        const gcdVal = gcd(Math.abs(molecular), Math.abs(denominator));
        return [(molecular / gcdVal) >> 0, (denominator / gcdVal) >> 0];
    }
}