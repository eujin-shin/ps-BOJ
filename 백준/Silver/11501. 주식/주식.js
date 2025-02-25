const fs = require("fs");
const [, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

function solution(arr) {
  return arr
    .reverse()
    .reduce(
      ([max, sum], v) => [Math.max(max, v), (sum += Math.max(0, max - v))],
      [0, 0]
    )[1];
}

while (input.length > 0) {
  console.log(solution(input.splice(0, 2)[1].split(" ").map(Number)));
}
