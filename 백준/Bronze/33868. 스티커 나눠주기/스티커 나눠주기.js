const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, ...submits] = input.map((str) => str.split(" ").map(Number));

function solution(submits) {
  const [t, b] = submits.reduce(
    ([max, min], [a, b]) => [Math.max(a, max), Math.min(b, min)],
    [-Infinity, Infinity]
  );
  return ((t * b) % 7) + 1;
}

console.log(solution(submits));
