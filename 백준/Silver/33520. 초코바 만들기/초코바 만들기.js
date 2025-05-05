const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [, ...chocolates] = input.map((str) => str.split(" ").map(Number));

function solution(chocolates) {
  let min = Math.min(...chocolates[0]);
  let max = Math.max(...chocolates[0]);
  for (let i = 1; i < chocolates.length; i++) {
    min = Math.max(min, Math.min(...chocolates[i]));
    max = Math.max(max, Math.max(...chocolates[i]));
  }
  return (BigInt(min) * BigInt(max)).toString();
}

console.log(solution(chocolates));
