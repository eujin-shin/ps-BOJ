const fs = require("fs");
const n = Number(fs.readFileSync("/dev/stdin").toString().trim());
let x = 0;
const records = new Set([0]);
for (let i = 1; i <= n; i++)
  records.add((x = x - i < 0 || records.has(x - i) ? x + i : x - i));
console.log(x);
