const fs = require("fs");
const n = Number(fs.readFileSync("/dev/stdin").toString().trim());
const MOD = 1000000007;
let x = 0;
for (let i = 1; i <= n; i++) x = (x * 3 + 2) % MOD;
console.log(x);
