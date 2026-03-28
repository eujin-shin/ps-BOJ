const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, arr] = input.map((str) => str.split(" ").map(Number));
const answer = arr
  .sort((a, b) => a - b)
  .reduce((cur, v) => Math.max(cur, v) + 1, 0);
console.log(answer);
