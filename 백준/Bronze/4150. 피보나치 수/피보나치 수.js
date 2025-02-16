const fs = require("fs");
const n = Number(fs.readFileSync("/dev/stdin").toString().trim());

function solution(n) {
  const arr = [0n, 1n];
  for (let i = 2; i <= n; i += 2) {
    arr[0] += arr[1];
    arr[1] += arr[0];
  }
  return arr[n % 2].toString();
}

console.log(solution(n));
