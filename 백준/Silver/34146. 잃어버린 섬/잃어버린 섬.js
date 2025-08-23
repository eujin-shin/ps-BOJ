const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n, m], ...numbers] = input.map((str) => str.split(" ").map(Number));
const counts = new Map();
for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    const x = numbers[i][j];
    counts.set(x, (counts.get(x) || 0) + 1);
  }
}
const odds = [...counts.values()].filter((v) => v % 2 === 1).length;
console.log(
  (m % 2 === 1 && odds <= n) || (m % 2 === 0 && odds === 0) ? "YES" : "NO"
);
