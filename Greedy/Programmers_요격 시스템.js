function solution(targets) {
    targets.sort((a, b) => b[0] - a[0]);
  
    let answer = 1;
    let minStart = targets[0][0];
  
    for (let i = 1; i < targets.length; i++) {
      const [start, end] = targets[i];
  
      if (end <= minStart) {
        minStart = start;
        answer++;
      }
    }
  
    return answer;
  }