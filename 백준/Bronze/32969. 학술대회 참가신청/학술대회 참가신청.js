const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();

function solution(input) {
  return input.includes("bigdata") ||
    input.includes("public") ||
    input.includes("society")
    ? "public bigdata"
    : "digital humanities";
}

console.log(solution(input));
