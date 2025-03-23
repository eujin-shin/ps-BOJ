const fs = require("fs");
const [firstLine, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const [n, m] = firstLine.split(" ").map(Number);
const orders = input.splice(-m).map((str) => str.split(" ").map(Number));

function solution(n, orders) {
  const sum = orders.reduce((acc, [, v]) => acc + v, 0);
  return sum / n;
}

console.log(solution(n, orders));
