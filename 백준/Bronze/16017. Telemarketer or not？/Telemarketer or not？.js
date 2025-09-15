const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [a, b, c, d] = input.map(Number);
console.log(
  (a === 8 || a === 9) && (d === 8 || d === 9) && b === c ? "ignore" : "answer"
);
