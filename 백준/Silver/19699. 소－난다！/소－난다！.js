const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n, m], cows] = input.map((str) => str.split(" ").map(Number));
const MAX = 10000;
const prime = Array.from({ length: MAX }, () => true);
for (let i = 2; i < MAX; i++) {
  for (let x = i * 2; x < MAX; x += i) prime[x] = false;
}
const answer = new Set();
const calc = (sum, r, x) => {
  if (r === m) {
    if (prime[sum]) answer.add(sum);
    return;
  }
  for (let i = x; i < n; i++) calc(sum + cows[i], r + 1, i + 1);
};
calc(0, 0, 0);
console.log(
  answer.size === 0 ? -1 : [...answer].sort((a, b) => a - b).join(" ")
);
