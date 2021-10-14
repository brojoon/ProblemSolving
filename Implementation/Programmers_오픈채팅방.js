function solution(record) {
  let arr = [];
  var answer = [];
  for (let i = 0; i < record.length; i++) arr.push(record[i].split(" "));
  let userId = new Set();
  let userNick = new Map();
  for (let i = record.length - 1; i >= 0; i--) {
    if (!userId.has(arr[i][1])) {
      if (arr[i][0] != "Leave") {
        userId.add(arr[i][1]);
        userNick.set(arr[i][1], arr[i][2]);
      }
    }
  }
  for (let i = 0; i < record.length; i++) {
    let result = "";
    if (arr[i][0] == "Enter") {
      result += userNick.get(arr[i][1]);
      result += "님이 들어왔습니다.";
      answer.push(result);
    } else if (arr[i][0] == "Leave") {
      result += userNick.get(arr[i][1]);
      result += "님이 나갔습니다.";
      answer.push(result);
    }
  }

  return answer;
}
