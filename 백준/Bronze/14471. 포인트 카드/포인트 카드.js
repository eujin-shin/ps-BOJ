const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], ...stamps] = input.map((str) => str.split(" ").map(Number));

function solution(n, stamps) {
  const sorted = stamps.sort((a, b) => a[0] - b[0]).slice(1);
  return sorted.reduce((sum, [a]) => sum + Math.max(0, n - a), 0);
}

console.log(solution(n, stamps));
