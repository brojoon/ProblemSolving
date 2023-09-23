function getDivisorsLength(num) {
  const divisors = [];
  for (let i = 1; i <= Math.sqrt(num); i++) {
    if (num % i === 0) {
      divisors.push(i);
      if (num / i != i) divisors.push(num / i);
    }
  }
  return divisors.length;
}

function solution(number, limit, power) {
  let answer = 0;

  for (let i = 1; i <= number; i++) {
    let attack = getDivisorsLength(i);
    answer += attack > limit ? power : attack;
  }
  return answer;
}
