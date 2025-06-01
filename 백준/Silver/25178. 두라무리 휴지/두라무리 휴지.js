const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

function solution(n, a, b) {
  return a[0] === b[0] &&
    a[n - 1] === b[n - 1] &&
    [...a].sort().join("") === [...b].sort().join("") &&
    a.replace(/[aeiou]/gi, "") === b.replace(/[aeiou]/gi, "")
    ? "YES"
    : "NO";
}

console.log(solution(Number(input[0]), input[1], input[2]));
