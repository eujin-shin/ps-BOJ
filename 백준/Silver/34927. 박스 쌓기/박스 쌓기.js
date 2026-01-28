const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const box = input[1]
  .split(" ")
  .map(Number)
  .sort((a, b) => a - b);
const [count] = box.reduce(
  ([count, sum], cur) => (cur >= sum ? [count + 1, sum + cur] : [count, sum]),
  [0, 0]
);
console.log(count);
