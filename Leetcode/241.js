/**
 * 241. 为运算表达式设计优先级
 * link：https://leetcode.cn/problems/different-ways-to-add-parentheses/
 */

/**
 * @param {string} expression
 * @return {number[]}
 */
var diffWaysToCompute = function (expression) {
    let index = 0;

    const parseUnsignedInt = function (subexpression) {
        let value = 0;
        for (const ch of subexpression) {
            if (ch < '0' || ch > '9') {
                return -1;
            }
            value = value * 10 + (ch - '0');
        }
        return value;
    }

    const arrayCrossCalculate = function (leftOperand, rightOperand, operator) {
        const answer = [];
        for (const left of leftOperand) {
            for (const right of rightOperand) {
                let result;
                if (operator === '+') {
                    result = left + right;
                } else if (operator === '-') {
                    result = left - right;
                } else if (operator === '*') {
                    result = left * right;
                } else {
                    result = left / right;
                }
                answer.push(result);
            }
        }
        return answer;
    }

    const operatorArray = ['+', '-', '*', '/'];
    const parseExpression = function (subexpression) {
        const value = parseUnsignedInt(subexpression);
        if (value >= 0) {
            return [value];
        }

        const answer = [];
        for (let i = 0; i < subexpression.length; i++) {
            const operator = subexpression[i];
            if (operatorArray.includes(operator)) {
                const leftOperand = parseExpression(subexpression.substring(0, i));
                const rightOperand = parseExpression(subexpression.substring(i + 1));
                Array.prototype.push.apply(answer, arrayCrossCalculate(leftOperand, rightOperand, operator));
            }
        }
        return answer;
    }

    return parseExpression(expression);
};