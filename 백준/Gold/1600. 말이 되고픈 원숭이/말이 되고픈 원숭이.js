const fs = require("fs");
const [firstLine, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const k = Number(firstLine);
const [[w, h], ...board] = input.map((str) => str.split(" ").map(Number));

function solution(k, w, h, board) {
  const visit = Array.from({ length: w }, () =>
    Array.from({ length: h }, () => Array.from({ length: k + 1 }, () => 0))
  );
  const monkey = [
    [1, 0],
    [-1, 0],
    [0, -1],
    [0, 1],
  ];
  const horse = [
    [-2, -1],
    [-1, -2],
    [1, -2],
    [2, -1],
    [-2, 1],
    [-1, 2],
    [1, 2],
    [2, 1],
  ];

  const isValidPos = (x, y) =>
    x < w && x >= 0 && y < h && y >= 0 && board[y][x] === 0;

  const queue = [[0, 0, 0]];
  let front = 0;
  visit[0][0][0] = 1;

  while (front < queue.length) {
    const [x, y, count] = queue[front++];

    monkey.forEach(([xMove, yMove]) => {
      const nextX = x + xMove;
      const nextY = y + yMove;
      if (
        isValidPos(nextX, nextY) &&
        (visit[nextX][nextY][count] === 0 ||
          visit[nextX][nextY][count] > visit[x][y][count] + 1)
      ) {
        queue.push([nextX, nextY, count]);
        visit[nextX][nextY][count] = visit[x][y][count] + 1;
      }
    });

    if (count < k) {
      horse.forEach(([xMove, yMove]) => {
        const nextX = x + xMove;
        const nextY = y + yMove;
        if (
          isValidPos(nextX, nextY) &&
          (visit[nextX][nextY][count + 1] === 0 ||
            visit[nextX][nextY][count + 1] > visit[x][y][count] + 1)
        ) {
          queue.push([nextX, nextY, count + 1]);
          visit[nextX][nextY][count + 1] = visit[x][y][count] + 1;
        }
      });
    }
  }

  return (
    visit[w - 1][h - 1].reduce(
      (ans, cur) => (ans === 0 || (cur > 0 && cur < ans) ? cur : ans),
      0
    ) - 1
  );
}

console.log(solution(k, w, h, board));
