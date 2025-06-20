const fs = require("fs");
const [n, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
for (let i = 0; i < Number(n); i++) {
  console.log(input[i]);
  const [a, b] = input[i].split(" ").map(Number);
  console.log(a * b - Math.max(0, a - 1) * 2);
}
