const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
let min;
const sum = input[1].split(" ").reduce((prev, cur) => {
  const x = BigInt(cur);
  min = min === undefined || x < min ? x : min;
  return prev + x;
}, 0n);
console.log((sum - min * BigInt(input[0])).toString());
