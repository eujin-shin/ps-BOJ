const fs = require("fs");
const [firstLine, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
const [n, s] = firstLine.split(" ").map(Number);
const cows = input.map(Number).sort((a, b) => a - b);
let x = 0;
let y = n - 1;
let count = 0;
while (x < y) {
  if (cows[x] + cows[y] > s) {
    y--;
  } else {
    count += y - x;
    x++;
  }
}
console.log(count);
