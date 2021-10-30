function is_valid_place(place) {
  const is_reserved = Array.from(Array(5), () => Array(5).fill(false));
  const dx = [1, -1, 0, 0];
  const dy = [0, 0, 1, -1];
  for (let i = 0; i < place.length; i++) {
    for (let j = 0; j < place[i].length; j++) {
      if (place[i][j] == "P") {
        for (let k = 0; k < 4; k++) {
          let ydy = i + dy[k];
          let xdx = j + dx[k];

          if (
            ydy < place.length &&
            ydy >= 0 &&
            xdx < place[i].length &&
            xdx >= 0
          ) {
            if (place[ydy][xdx] == "P") return 0;
            else if (place[ydy][xdx] == "O") {
              if (is_reserved[ydy][xdx]) return 0;
              is_reserved[ydy][xdx] = true;
            }
          }
        }
      }
    }
  }
  return 1;
}

function solution(places) {
  let answer = [];
  for (let i = 0; i < 5; i++) answer.push(is_valid_place(places[i]));
  return answer;
}
