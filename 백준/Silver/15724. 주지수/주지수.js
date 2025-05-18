const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n, m], ...rest] = input.map((str) => str.split(" ").map(Number));
const country = rest.splice(0, n);
const queries = rest.slice(1);

function solution(n, m, country, queries) {
  const sumList = Array.from({ length: n + 1 }, () =>
    Array.from({ length: m + 1 }, () => 0)
  );
  for (let y = 1; y <= n; y++) {
    for (let x = 1; x <= m; x++) {
      sumList[y][x] =
        country[y - 1][x - 1] +
        sumList[y - 1][x] +
        sumList[y][x - 1] -
        sumList[y - 1][x - 1];
    }
  }
  queries.forEach(([yStart, xStart, yEnd, xEnd]) => {
    console.log(
      sumList[yEnd][xEnd] -
        sumList[yEnd][xStart - 1] -
        sumList[yStart - 1][xEnd] +
        sumList[yStart - 1][xStart - 1]
    );
  });
}

solution(n, m, country, queries);
