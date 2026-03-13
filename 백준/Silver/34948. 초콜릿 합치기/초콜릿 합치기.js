const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, height, width] = input.map((str) => str.split(" ").map(Number));
const sum = new Map();
width.forEach((v, idx) =>
  sum.set(height[idx], (sum.get(height[idx]) || 0) + v)
);
const [max] = [...sum]
  .sort((a, b) => b[0] - a[0])
  .reduce(([max, w], [h, v]) => [Math.max(max, (w + v) * h), w + v], [0, 0]);
console.log(max);
