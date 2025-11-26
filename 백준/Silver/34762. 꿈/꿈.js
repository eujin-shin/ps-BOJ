const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n, k], [m], days] = input.map((str) => str.split(" ").map(Number));
let start = 0;
let flag = true;
for (let i = 0; i < m; i++) {
  const day = days[i];
  if (start !== 0 && day !== start && day - start <= k) {
    flag = false;
    break;
  }
  start = day + 1;
}
flag = flag && (n < start || n - start + 1 > k);
console.log(flag ? "YES" : "NO");
