const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[p, n], list] = input.map((str) => str.split(" ").map(Number));

function solution(p, n, list) {
  const sorted = list.sort((a, b) => a - b);
  for (let i = 0; i < n; i++) {
    if (200 <= p) {
      return i;
    }
    p += sorted[i];
  }
  return n;
}

console.log(solution(p, n, list));
