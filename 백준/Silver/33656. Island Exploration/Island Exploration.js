const fs = require("fs");
const [firstLine, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
const [r, c] = firstLine.split(" ").map(Number);

function solution(r, c, input) {
  const findStart = () => {
    for (let i = 0; i < r; i++) {
      const temp = input[i].indexOf("S");
      if (temp !== -1) {
        return [temp, i];
      }
    }
  };

  const moves = [
    [0, -1],
    [0, 1],
    [1, 0],
    [-1, 0],
  ];
  let count = 1;
  const queue = [findStart()];
  const visit = Array.from({ length: r }, () =>
    Array.from({ length: c }, () => 0)
  );
  visit[queue[0][1]][queue[0][0]] = 1;
  while (queue.length !== 0) {
    const [x, y] = queue.shift();
    for (let i = 0; i < 4; i++) {
      const tempX = x + moves[i][0];
      const tempY = y + moves[i][1];
      if (input[tempY]?.[tempX] === "#" && visit[tempY]?.[tempX] === 0) {
        count++;
        visit[tempY][tempX] = 1;
        queue.push([tempX, tempY]);
      }
    }
  }
  return count;
}

console.log(solution(r, c, input));
