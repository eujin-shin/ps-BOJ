const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n, m], top, left] = input.map((str) => str.split(" ").map(Number));

function solution(n, m, top, left) {
  const flowers = Array.from({ length: m + 1 }, (_, y) =>
    Array.from({ length: n + 1 }, (_, x) =>
      y === 0 ? top[x - 1] : x === 0 ? left[y - 1] : 0
    )
  );
  for (let y = 1; y <= m; y++) {
    for (let x = 1; x <= n; x++) {
      flowers[y][x] = flowers[y - 1][x] === flowers[y][x - 1] ? 0 : 1;
    }
  }
  return flowers[m][n];
}

console.log(solution(n, m, top, left));
