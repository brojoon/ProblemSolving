let operator = [];
let priority = [];
let select = [];
let numbers = [];
let oper_type = new Map();
let answer = 0;

function setting(expression) {
    let s = '';
    oper_type[0] = '*';
    oper_type[1] = '+';
    oper_type[2] = '-';
    for (let i = 0; i < expression.length; i++) {
        if (expression[i] % 1 === 0) s += expression[i];
        else {
            numbers.push(s);
            operator.push(expression[i]);
            s = '';
        }
    }
    numbers.push(s);
}

function calculate(N1, N2, op) {
    if (op == '*') return N1 * N2;
    else if (op == '+') return N1 + N2;
    else if (op == '-') return N1 - N2;
}

function find_result() {
    let tmp_operator = [...operator];
    let tmp_numbers = [...numbers];
    for (let i = 0; i < 3; i++) {
        let c = priority[i];
        for (let j = 0; j < tmp_operator.length; j++) {
            if (tmp_operator[j] == c) {
                let result = calculate(parseInt(tmp_numbers[j]), parseInt(tmp_numbers[j + 1]), c);
                tmp_numbers[j] = result;
                tmp_numbers.splice(j + 1, 1);
                tmp_operator.splice(j, 1);
                j--;
            }
        }
    }
    return Math.abs(tmp_numbers[0]);
}

function dfs(cnt) {
    if (cnt === 3) {
        let result = find_result();
        answer = Math.max(answer, result);
        return;
    }
    for (let i = 0; i < 3; i++) {
        if (select[i] === true) continue;
        select[i] = true;
        priority.push(oper_type[i]);
        dfs(cnt + 1);
        priority.pop();
        select[i] = false;
    }
}

function solution(expression) {
    setting(expression);
    dfs(0);
    return answer;
}