function solution(n) {
  const arr = ["4", "1", "2"];
  let answer = "";

  while (n) {
    answer = arr[n % 3] + answer;
    if (!(n % 3)) {
      n = parseInt(n / 3) - 1;
    } else {
      n = parseInt(n / 3);
    }
  }
  return answer;
}

console.log(solution(4));
