function isPrime(num) {
  for (let i = 2; i <= Math.sqrt(num); i++) {
    if (num % i === 0) return false;
  }
  return true;
}

function solution(nums) {
  let answer = 0;
  for (let x = 0; x < nums.length - 2; x++) {
    for (let y = x + 1; y < nums.length - 1; y++) {
      for (let z = y + 1; z < nums.length; z++) {
        if (isPrime(nums[x] + nums[y] + nums[z])) answer++;
      }
    }
  }
  return answer;
}
