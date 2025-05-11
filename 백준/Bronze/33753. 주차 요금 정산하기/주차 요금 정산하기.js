const fs = require("fs");
const [firstLine, input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const [a, b, c] = firstLine.split(" ").map(Number);
const t = Number(input);

console.log(a + Math.ceil(Math.max(t - 30, 0) / b) * c);
