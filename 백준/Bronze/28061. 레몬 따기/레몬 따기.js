const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], lemon] = input.map((str) => str.split(" ").map(Number));
console.log(lemon.reduce((max, cur, idx) => Math.max(max, cur - (n - idx)), 0));
