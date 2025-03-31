const fs = require("fs");
const [, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

function solution(n, m) {
  const two = n - m;
  return `${m - two} ${two}`;
}

input.forEach((str) => {
  console.log(solution(...str.split(" ").map(Number)));
});
