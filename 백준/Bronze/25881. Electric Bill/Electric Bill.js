const fs = require("fs");
const [firstLine, , ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
const [a, b] = firstLine.split(" ").map(Number);
input.forEach((v) => {
  const n = Number(v);
  console.log(n, Math.min(n, 1000) * a + Math.max(0, n - 1000) * b);
});
