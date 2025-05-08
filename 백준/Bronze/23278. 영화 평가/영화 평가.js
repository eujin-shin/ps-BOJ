const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n, l, h], scores] = input.map((str) => str.split(" ").map(Number));

function solution(n, l, h, scores) {
  return (
    scores
      .sort((a, b) => a - b)
      .slice(l, n - h)
      .reduce((sum, v) => sum + v, 0) /
    (n - (l + h))
  );
}

console.log(solution(n, l, h, scores));
