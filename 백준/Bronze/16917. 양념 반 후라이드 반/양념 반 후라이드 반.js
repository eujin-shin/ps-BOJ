const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();
const [a, b, c, x, y] = input.split(" ").map(Number);
const [min, max] = x < y ? [x, y] : [y, x];
console.log(
  a + b <= 2 * c
    ? x * a + y * b
    : min * 2 * c + (max - min) * Math.min(max === x ? a : b, c * 2)
);
