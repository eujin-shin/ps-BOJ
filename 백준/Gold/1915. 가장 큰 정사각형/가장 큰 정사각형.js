const fs = require("fs");
const [firstLine, ...arr] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const [n, m] = firstLine.split(" ").map(Number);

function solution(n, m, arr) {
  const dp = [];

  let max = 0;
  for (let y = 0; y < n; y++) {
    const row = [];
    for (let x = 0; x < m; x++) {
      const cell =
        arr[y][x] === "0"
          ? { x: 0, y: 0 }
          : {
              x: 1 + (row[x - 1]?.x || 0),
              y: 1 + (dp[y - 1]?.[x]?.y || 0),
            };
      const square = Math.min(
        cell.x,
        cell.y,
        (dp[y - 1]?.[x - 1]?.square || 0) + 1
      );
      max = square < max ? max : square;
      cell.square = square;
      row.push(cell);
    }
    dp.push(row);
  }
  return max ** 2;
}

console.log(solution(n, m, arr));
