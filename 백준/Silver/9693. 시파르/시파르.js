const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
for (let i = 0; i < input.length - 1; i++) {
  const n = Number(input[i]);
  let count = 0;
  for (let x = 5; x <= n; x *= 5) count += Math.floor(n / x);
  console.log(`Case #${i + 1}: ${count}`);
}
