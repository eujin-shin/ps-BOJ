const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [firstLine, ...id] = input;
const n = Number(firstLine);
let count = 1;
while (1) {
  const set = new Set(id.map((v) => v.slice(-count)));
  if (set.size === n) break;
  count++;
}
console.log(count);
