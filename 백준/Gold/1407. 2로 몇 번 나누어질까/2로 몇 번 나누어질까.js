const fs = require("fs");
const [a, b] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ")
  .map(Number);

function solution(a, b) {
  let prev = 1n,
    sum = 0n;
  for (let x = 1; x <= b; x *= 2) {
    const cur = Math.floor(b / x) - Math.ceil(a / x) + 1;
    sum += BigInt(cur) * prev;
    prev = BigInt(x);
  }
  return sum.toString();
}

console.log(solution(a, b));
