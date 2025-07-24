const fs = require("fs");
const [x, y, a, b] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ")
  .map(Number);
function init() {
  return a < b ? [a, x, b, y, b % y] : [b, y, a, x, a % x];
}
const [start, add, bound, key, mod] = init();
const arr = Array.from({ length: key }, () => 0);
let i = start;
let answer = -1;
while (i < bound || arr[i % key] === 0) {
  if (bound <= i) {
    if (i % key === mod) {
      answer = i;
      break;
    }
    arr[i % key] = 1;
  }
  i += add;
}
console.log(answer);
