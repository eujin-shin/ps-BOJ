const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [b, x] = input[0].split(" ");
const n = Number(x);
const prices = new Map(input.slice(1, 1 + n).map((str) => str.split(" ")));
const need = input
  .slice(1 + n)
  .reduce((prev, cur) => prev + BigInt(prices.get(cur)), 0n);
console.log(need > BigInt(b) ? "unacceptable" : "acceptable");
