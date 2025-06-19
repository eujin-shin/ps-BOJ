const fs = require("fs");
const [a, b, c] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ")
  .map(Number);
console.log(a * b === a + b * c ? 0 : a * b < a + b * c ? 1 : 2);
