const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [n, k] = input[0].split(" ").map(Number);
const arr = Array.from({ length: n }, (_, idx) => idx === 0);
for (let i = 0; i < n; i++) {
  if (!arr[i]) continue;
  arr[i + 1] = arr[i + 1] || (i + 1 < n && input[1][i + 1] !== "#");
  arr[i + k] = arr[i + k] || (i + k < n && input[1][i + k] !== "#");
}
console.log(arr[n - 1] ? "YES" : "NO");
