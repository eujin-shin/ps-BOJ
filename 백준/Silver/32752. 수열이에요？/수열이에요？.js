const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n, l, r], arr] = input.map((str) => str.split(" ").map(Number));
const isSorted = arr
  .slice(0, l - 1)
  .concat(...arr.slice(r))
  .every((v, idx, arr) => idx === 0 || arr[idx - 1] <= v);
const replaced = arr.slice(l - 1, r).sort((a, b) => a - b);
console.log(
  isSorted &&
    (l === 1 || arr[l - 2] <= replaced[0]) &&
    (r === n || replaced[r - l] <= arr[r])
    ? 1
    : 0
);
