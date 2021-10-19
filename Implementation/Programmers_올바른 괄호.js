function solution(s) {
  let balance = 0;

  for (let i = 0; i < s.length; i++) {
    if (s[i] === "(") balance++;
    else balance--;
    if (balance < 0) break;
  }
  return balance === 0 ? true : false;
}
