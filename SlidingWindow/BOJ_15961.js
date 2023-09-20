const fs = require("fs");
const input = fs.readFileSync("/dev/stdin", "utf-8").split("\n"); // 테스트용
const [N, D, K, C] = input[0].split(" ").map((n) => Number(n));
const sushi = input.slice(1, input.length).map((n) => Number(n));
const sushiType = new Array(3001).fill(0);
const myDeque = [];
let answer = 0;

for (let i = 0; i < K; i++) {
  myDeque.push(sushi[i]);
  if (!sushiType[sushi[i]]) answer++;
  sushiType[sushi[i]]++;
}

let cnt = answer;
if (!sushiType[C]) answer = Math.max(answer, cnt + 1);

for (let i = 0; i < N - 1; i++) {
  myDeque.shift();
  if (!--sushiType[sushi[i]]) cnt--;
  myDeque.push(sushi[(i + K) % N]);
  if (!sushiType[sushi[(i + K) % N]]++) cnt++;
  if (!sushiType[C]) answer = Math.max(answer, cnt + 1);
  else answer = Math.max(answer, cnt);
}

console.log(answer);
