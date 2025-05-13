const fs = require("fs");
const numbers = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map(Number);

function solution(n) {
  const arr = [n];
  while (9 < n) {
    n = String(n)
      .split("")
      .reduce((acc, cur) => acc * cur, 1);
    arr.push(n);
  }
  return arr.join(" ");
}

numbers.slice(0, -1).forEach((v) => console.log(solution(v)));
