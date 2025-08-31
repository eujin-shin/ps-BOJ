const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const n = Number(input[0]);
const arr = input[1]
  .split(" ")
  .map(BigInt)
  .sort((a, b) => Number(a - b));
const sum = arr.reduce((prev, cur) => prev + cur, 0n);
const a = arr[0] * arr[1] * 2n - (arr[0] + arr[1]);
const b = arr[n - 1] * arr[n - 2] * 2n - (arr[n - 1] + arr[n - 2]);
console.log((sum + (a < 0n && b < 0n ? 0n : a > b ? a : b)).toString());
