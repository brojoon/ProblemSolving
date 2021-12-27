function solution(people, limit) {
  let count = 0;
  people.sort((a, b) => {
    return a - b;
  });
  for (let i = people.length - 1; count < i; i--) {
    if (people[count] + people[i] <= limit) count++;
  }
  return people.length - count;
}
