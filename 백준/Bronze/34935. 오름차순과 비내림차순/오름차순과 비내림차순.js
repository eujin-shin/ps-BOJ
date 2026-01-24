const fs = require("fs");
const [, input] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const isAsc = input
  .split(" ")
  .every((v, idx, arr) => idx === 0 || v !== arr[idx - 1]);
console.log(isAsc ? 1 : 0);
