const fs = require("fs");
const n = Number(fs.readFileSync("/dev/stdin").toString().trim());
const MOD = 1000000007;
let odd = 2;
let even = 24;
for (let i = 1; i < n; i++) {
  const nextEven = (odd * 2 + even * 24) % MOD;
  const nextOdd = (even * 2 + odd * 24) % MOD;
  odd = nextOdd;
  even = nextEven;
}
console.log(even);
