/**
 * 736. Lisp 语法解析
 * link：https://leetcode.cn/problems/parse-lisp-expression/
 */

/**
 * @param {string} expression
 * @return {number}
 */
var evaluate = function (expression) {
    const variables_scope = new Map();
    let index = 0;

    const parseInt = (expression) => {
        let sign = 1, value = 0;
        if (expression[index] === '-') {
            sign = -1;
            index++;
        }
        while (index < expression.length && isDigit(expression[index])) {
            value = value * 10 + (expression.charAt(index) - '0');
            index++;
        }
        return sign * value;
    }

    const parseVariable = (expression) => {
        let variable = '';
        while (index < expression.length && expression[index] != ' ' && expression[index] != ')') {
            variable += expression[index];
            index++;
        }
        return variable;
    }

    const parse = (expression) => {
        if (expression[index] !== '(') {
            if (isLowerCase(expression[index])) {
                const variable = parseVariable(expression);
                const variable_value = variables_scope.get(variable);
                return variable_value[variable_value.length - 1];
            } else {
                return parseInt(expression);
            }
        }
        index++;
        let result;
        if (expression[index] === 'l') { // let
            index += 4;
            const variables = [];
            while (true) {
                if (!isLowerCase(expression[index])) {
                    result = parse(expression);
                    break;
                }
                let variable = parseVariable(expression);
                if (expression[index] === ')') {
                    const variable_value = variables_scope.get(variable);
                    result = variable_value[variable_value.length - 1];
                    break;
                }
                variables.push(variable);
                index++;
                let value = parse(expression);
                if (!variables_scope.has(variable)) {
                    variables_scope.set(variable, []);
                }
                variables_scope.get(variable).push(value);
                index++;
            }
            for (const variable of variables) {
                variables_scope.get(variable).pop();
            }
        } else if (expression[index] === 'a') { // add
            index += 4;
            const lhs = parse(expression);
            index++;
            const rhs = parse(expression);
            result = lhs + rhs;
        } else { // mult
            index += 5;
            const lhs = parse(expression);
            index++;
            const rhs = parse(expression);
            result = lhs * rhs;
        }
        index++;
        return result;
    }

    return parse(expression);
};

const isLowerCase = (ch) => {
    return ch >= 'a' && ch <= 'z';
}

const isDigit = (ch) => {
    return ch >= '0' && ch <= '9';
}