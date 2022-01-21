const fs = require('fs');
// const input = fs.readFileSync('/dev/stdin', 'utf-8').split(' '); // 제출용
const input = fs.readFileSync('./input.txt', 'utf-8').split(' ').map((c) => Number(c)); // 테스트용

if (input[0] < input[1]) console.log('<');
else if (input[0] > input[1]) console.log('>');
else console.log('==');
