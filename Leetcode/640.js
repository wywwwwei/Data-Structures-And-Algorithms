/**
 * 640. 求解方程
 * link：https://leetcode.cn/problems/solve-the-equation/
 */

/**
 * @param {string} equation
 * @return {string}
 */
var solveEquation = function (equation) {
    const [leftExpression, rightExpression] = equation.split("=");
    const isDigit = (ch) => (ch >= "0" && ch <= "9");
    const parseExpression = function (exp) {
        let coefficient = 0, constant = 0;
        const n = exp.length;
        let currentConstant = 0, isNegative = false;
        for (let i = 0; i < n; i++) {
            if (exp[i] === "+" || exp[i] === "-") {
                constant += (isNegative ? -currentConstant : currentConstant);
                isNegative = (exp[i] === "-");
                currentConstant = 0;
            } else if (exp[i] === "x") {
                // If the last digit is not a number, the initialization coefficient is 1
                if (i === 0 || !isDigit(exp[i - 1])) {
                    currentConstant = 1;
                }
                coefficient += (isNegative ? -currentConstant : currentConstant);
                currentConstant = 0;
            } else {
                currentConstant = currentConstant * 10 + Number(exp[i]);
            }
        }
        return [coefficient, constant + (isNegative ? -currentConstant : currentConstant)];
    }

    const [leftCoefficient, leftConstant] = parseExpression(leftExpression);
    const [rightCoefficient, rightConstant] = parseExpression(rightExpression);
    if (leftCoefficient === rightCoefficient) {
        if (rightConstant - leftConstant === 0) {
            return "Infinite solutions";
        } else {
            return "No solution";
        }
    } else {
        return "x=" + (rightConstant - leftConstant) / (leftCoefficient - rightCoefficient);
    }
};