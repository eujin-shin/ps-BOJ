const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[, x, k], ...changes] = input.map((str) => str.split(" ").map(Number));
function solution(x, k, changes) {
  for (let i = 0; i < k; i++) {
    const [a, b] = changes[i];
    x = a === x ? b : b === x ? a : x;
  }
  return x;
}
console.log(solution(x, k, changes));
