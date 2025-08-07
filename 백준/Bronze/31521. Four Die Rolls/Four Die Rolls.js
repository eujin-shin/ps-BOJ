const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], numbers] = input.map((str) => str.split(" ").map(Number));
const total = Math.pow(6, 4 - n);
let diff = 1;
for (let x = 6 - n; x > 2; x--) diff *= x;
const a = new Set(numbers).size === n ? diff : 0;
console.log(a, total - a);
