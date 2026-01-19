const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const n = Number(input[0]);
for (let i = 2, k = 0; k < n; i += 2, k++)
  console.log(new Set(input[i].split(" ").map(Number)).size * 2 - 1);
