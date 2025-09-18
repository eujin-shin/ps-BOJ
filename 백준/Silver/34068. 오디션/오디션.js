const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], ...records] = input.map((str) => str.split(" ").map(Number));
let max = 0;
const arr = Array.from({ length: n }, () => 0);
records.forEach(([v]) => {
  arr[v - 1]++;
  max = max < arr[v - 1] ? arr[v - 1] : max;
});
const counts = Array.from({ length: max + 1 }, () => 0n);
arr.forEach((v) => counts[v]++);
const [left, sum] = counts.reduce(
  ([prev, sum], cur) => [
    0n <= prev + cur - 1n ? prev + cur - 1n : 0n,
    sum + (0n <= prev + cur - 1n ? prev + cur - 1n : 0n),
  ],
  [0n, 0n]
);
console.log((sum + (left > 1n ? ((left - 1n) * left) / 2n : 0n)).toString());
