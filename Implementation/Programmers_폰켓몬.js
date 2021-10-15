function solution(nums) {
  const mySet = new Set(nums);
  return Math.min(mySet.size, nums.length / 2);
}
