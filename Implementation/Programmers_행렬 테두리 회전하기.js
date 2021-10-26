function solution(rows, columns, queries) {
  const answer = [];
  const board = Array(rows)
    .fill(0)
    .map(() => Array(columns));

  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < columns; j++) {
      board[i][j] = i * columns + j + 1;
    }
  }
  queries.forEach((query) => {
    const [x1, y1, x2, y2] = query.map((pos) => pos - 1);
    const Myqueue = [];
    for (let i = 0; i < y2 - y1; i++) Myqueue.push(board[x1][y1 + i]);
    for (let i = 0; i < x2 - x1; i++) Myqueue.push(board[x1 + i][y2]);
    for (let i = 0; i < y2 - y1; i++) Myqueue.push(board[x2][y2 - i]);
    for (let i = 0; i < x2 - x1; i++) Myqueue.push(board[x2 - i][y1]);
    Myqueue.unshift(Myqueue.pop());
    answer.push(Math.min(...Myqueue));
    for (let i = 0; i < y2 - y1; i++) board[x1][y1 + i] = Myqueue.shift();
    for (let i = 0; i < x2 - x1; i++) board[x1 + i][y2] = Myqueue.shift();
    for (let i = 0; i < y2 - y1; i++) board[x2][y2 - i] = Myqueue.shift();
    for (let i = 0; i < x2 - x1; i++) board[x2 - i][y1] = Myqueue.shift();
  });

  return answer;
}
