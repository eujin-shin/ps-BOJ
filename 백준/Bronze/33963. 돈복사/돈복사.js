const fs = require("fs");
const n = Number(fs.readFileSync("/dev/stdin").toString().trim());
function solution(n) {
  let i = 0;
  for (let x = 2; String(n).length === String(n * x).length; i++) {
    x *= 2;
  }
  return i;
}
console.log(solution(n));
