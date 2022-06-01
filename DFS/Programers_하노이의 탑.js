const answer = [];

function move(cur, next, sub, weight) {
  if (weight === 1) {
    answer.push([cur, next]);
  } else {
    move(cur, sub, next, weight - 1);
    answer.push([cur, next]);
    move(sub, next, cur, weight - 1);
  }
}

function solution(n) {
  move(1, 3, 2, n);

  return answer;
}
