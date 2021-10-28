function solution(maps) {
  const dx = [1, 0, -1, 0];
  const dy = [0, 1, 0, -1];
  const row = maps.length;
  const column = maps[0].length;
  const myQueue = [[0, 0]];
  const visited = maps.map((r) => r.map((c) => 1));

  while (myQueue.length) {
    const [y, x] = myQueue.shift();
    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (nx >= 0 && ny >= 0 && nx < column && ny < row) {
        if (maps[ny][nx] === 1 && visited[ny][nx] === 1) {
          visited[ny][nx] = visited[y][x] + 1;
          myQueue.push([ny, nx]);
        }
      }
    }
  }
  return visited[row - 1][column - 1] === 1 ? -1 : visited[row - 1][column - 1];
}
