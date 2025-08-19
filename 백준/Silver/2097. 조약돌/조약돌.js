const fs = require("fs");
const n = Number(fs.readFileSync("/dev/stdin").toString().trim());
const x = Math.floor(Math.sqrt(n));
function solution(n, x) {
  if (x * x === n) return (x - 1) * 4;
  else if (x * x + x >= n) return (x - 1) * 2 + x * 2;
  else return x * 4;
}
console.log(Math.max(4, solution(n, x)));
