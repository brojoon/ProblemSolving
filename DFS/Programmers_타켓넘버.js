function dfs(depth, numbers, acc, target) {
  if (depth >= numbers.length) {
    if (acc === target) return 1;
    else return 0;
  } else {
    let result = 0;
    result += dfs(depth + 1, numbers, acc + numbers[depth], target);
    result += dfs(depth + 1, numbers, acc - numbers[depth], target);
    return result;
  }
}

function solution(numbers, target) {
  let answer = 0;
  answer += dfs(0, numbers, 0, target);
  return answer;
}
