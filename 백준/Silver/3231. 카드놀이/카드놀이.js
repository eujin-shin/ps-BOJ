const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [n, ...cards] = input.map(Number);
const indices = Array.from({ length: n }, () => 0);
for (let i = 0; i < n; i++) indices[cards[i] - 1] = i;
const clap = indices.reduce(
  ([prev, sum], cur) => [cur, sum + (prev > cur ? 1 : 0)],
  [-1, 0]
)[1];
console.log(clap);
