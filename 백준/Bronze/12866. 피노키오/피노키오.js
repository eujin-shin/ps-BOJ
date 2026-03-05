const fs = require("fs");
const [, input] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [a, c, g, t] = input
  .split("")
  .reduce(
    (arr, v) => arr.map((x, idx) => ("ACGT"[idx] === v ? x + 1 : x)),
    [0, 0, 0, 0]
  )
  .map(BigInt);
console.log(((a * c * g * t) % 1000000007n).toString());
