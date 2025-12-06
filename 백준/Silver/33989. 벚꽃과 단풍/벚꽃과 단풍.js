const fs = require("fs");
const [, input] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const count = input
  .split("")
  .reduce(
    ([isB, isD], v) => [
      isB + (v === "B" ? 0 : 1),
      Math.min(isB, isD) + (v === "D" ? 0 : 1),
    ],
    [0, 0]
  );
console.log(Math.min(...count));
